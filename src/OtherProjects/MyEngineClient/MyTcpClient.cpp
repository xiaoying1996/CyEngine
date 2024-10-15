#include "MyTcpClient.h"

MyTcpClient* MyTcpClient::m_MyTcpClient = nullptr;
QMutex MyTcpClient::m_Mutex;
QMutex MyTcpClient::m_Mutex_Str;

MyTcpClient::MyTcpClient(QObject *parent)
	: QObject(parent)
{
    //初始化TCP服务器
    if (m_MyTcpClient == nullptr)
    {
        m_TcpClient = new QTcpSocket(this);
        connect(m_TcpClient, SIGNAL(connected()), this, SLOT(slot_connect_Success()));
        connect(m_TcpClient,SIGNAL(readyRead()),this,SLOT(slot_ReadData()));
        m_connectState = false;
        QFile file("data/config/TcpServer.config");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << QString::fromLocal8Bit("TCPServer Config文件读取失败\n");
            return;
        }
        else
        {
            QStringList configList;
            char* str = new char[100];
            qint64 readNum = file.readLine(str, 100);
            while (readNum != 0 && readNum != -1)
            {
                configList << QString::fromLocal8Bit(str);
                readNum = file.readLine(str, 100);
            }

            delete[100] str;
            file.close();
            for (int i = 0; i < configList.size(); i++)
            {
                QString s = configList[i];
                QStringList s_L = s.split("=");
                {
                    if (s_L.size() == 2 && s_L[0] == "IP")
                    {
                        m_IP = s_L[1];
                    }
                    else if(s_L.size() == 2 && s_L[0] == "PORT")
                    {
                        m_PORT = s_L[1].toUShort();
                    }
                }
            }
            m_TcpClient->connectToHost(QHostAddress(m_IP),m_PORT);
        }
    }
}

MyTcpClient::~MyTcpClient()
{}

MyTcpClient* MyTcpClient::GetInstance()
{
    if (m_MyTcpClient == nullptr)
    {
        m_Mutex.lock();
        if (m_MyTcpClient == nullptr)
        {
            m_MyTcpClient = new (std::nothrow) MyTcpClient(nullptr);
        }
        m_Mutex.unlock();
    }
    return m_MyTcpClient;
}

void MyTcpClient::deleteInstance()
{
    m_Mutex.lock();
    if (m_MyTcpClient)
    {
        delete m_MyTcpClient;
        m_MyTcpClient = nullptr;
    }
    m_Mutex.unlock();
}

void MyTcpClient::GetConnectState(bool& state)
{
    m_Mutex.lock();
    state = m_connectState;
    m_Mutex.unlock();
}

void MyTcpClient::SendMessage(QString str)
{
    m_TcpClient->write(str.toLocal8Bit());
}

void MyTcpClient::SendMessage(std::string str)
{
    m_TcpClient->write(str.c_str());
    m_TcpClient->flush();
}

void MyTcpClient::GetRetStrs(QVector<std::string>& strs)
{
    m_Mutex_Str.lock();
    strs = m_retStrs;
    m_retStrs.clear();
    m_Mutex_Str.unlock();
}

void MyTcpClient::slot_connect_Success()
{
    m_connectState = true;
}

void MyTcpClient::slot_disconnect()
{
    m_connectState = false;
}

void MyTcpClient::slot_ReadData()
{
    std::string str = m_TcpClient->readAll().toStdString();
    m_Mutex_Str.lock();
    m_retStrs.push_back(str);
    qDebug() << QString::fromLocal8Bit("从服务器收到数据:") << QString::fromStdString(str) << endl;
    m_Mutex_Str.unlock();
}
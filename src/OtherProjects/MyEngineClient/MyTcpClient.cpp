#include "MyTcpClient.h"

MyTcpClient* MyTcpClient::m_MyTcpClient = nullptr;
QMutex MyTcpClient::m_Mutex;

MyTcpClient::MyTcpClient(QObject *parent)
	: QObject(parent)
{
    //初始化TCP服务器
    if (m_MyTcpClient == nullptr)
    {
        m_TcpClient = new QTcpSocket(this);
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
            if (m_TcpClient->error() != QNetworkReply::NoError)
            {
                QMessageBox::information(NULL,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("TCP服务器连接失败,错误码:") + QString::number(m_TcpClient->error()),QMessageBox::Yes);
            }
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
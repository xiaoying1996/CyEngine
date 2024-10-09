#ifndef _MY_TCPCLIENT
#define _MY_TCPCLIENT

#include <QObject>
#include <QMutex>
#include <QtNetwork//QTcpSocket>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QHostAddress>
#include <QtNetwork>
#include <QMessageBox>

class MyTcpClient  : public QObject
{
	Q_OBJECT

public:
	~MyTcpClient();
	static MyTcpClient* GetInstance();
	static void deleteInstance();

	void GetConnectState(bool &state);
	void SendMessage(QString str);
	void SendMessage(std::string str);
	void GetRetStrs(QVector<std::string> &strs);

public slots:
	void slot_connect_Success();
	void slot_disconnect();
	void slot_ReadData();

private:
	MyTcpClient(QObject* parent);
	const MyTcpClient& operator=(const MyTcpClient& manager);
	static MyTcpClient* m_MyTcpClient;
	static QMutex m_Mutex;
	static QMutex m_Mutex_Str;

	QTcpSocket* m_TcpClient = nullptr;
	QString m_IP;
	unsigned short m_PORT;
	bool m_connectState;

	QVector<std::string> m_retStrs;
};

#endif // !_MY_TCPCLIENT

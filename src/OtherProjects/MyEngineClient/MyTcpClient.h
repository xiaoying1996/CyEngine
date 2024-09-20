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

private:
	MyTcpClient(QObject* parent);
	const MyTcpClient& operator=(const MyTcpClient& manager);
	static MyTcpClient* m_MyTcpClient;
	static QMutex m_Mutex;

	QTcpSocket* m_TcpClient = nullptr;
	QString m_IP;
	unsigned short m_PORT;
};

#endif // !_MY_TCPCLIENT

#include "SignUpWidget.h"

SignUpWidget::SignUpWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QPalette label_pe;
	label_pe.setColor(QPalette::WindowText, Qt::red);
	ui.WarnLabel->setPalette(label_pe);
	connect(ui.NameEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckInfoFilled(QString)));
	connect(ui.NumEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckInfoFilled(QString)));
	connect(ui.EmailEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckInfoFilled(QString)));
	connect(ui.PasswordEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckInfoFilled(QString)));
	connect(ui.Password2Edit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckInfoFilled(QString)));

	ui.PasswordEdit->setEchoMode(QLineEdit::Password);
	ui.Password2Edit->setEchoMode(QLineEdit::Password);


	m_inNameRepeat = false;
	m_inNumberRepeat = false;
	m_inEmailRepeat = false;
	m_infoRight = true;

	QString filename("material/pic/login/signup.png");
	QImage* img = new QImage;
	if (!(img->load(filename))) //����ͼ��
	{
		QMessageBox::information(this,
			tr("��ͼ��ʧ��"),
			tr("��ͼ��ʧ��!"));
		delete img;
		return;
	}
	//ui.PixLabel->resize(400, 140); //����label��С
	ui.PixLabel->setPixmap(QPixmap::fromImage(*img));
	//ui.label_2->setFixedSize(200, 40); //����label��С
	//ui.PixLabel->move(30,30);
	ui.PixLabel->setScaledContents(true); //��pixmapͼ����Ӧ��䵽label
}

SignUpWidget::~SignUpWidget()
{}

void SignUpWidget::SetUserNameRepeatState(bool state)
{
	if (state == true)
	{
		m_inNameRepeat = true;
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û����ظ�"));
		m_infoRight = false;
	}
	else if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
}

void SignUpWidget::SetNumberRepeatState(bool state)
{
	if (state == true)
	{
		m_inNumberRepeat = true;
		ui.WarnLabel->setText(QString::fromLocal8Bit("�ֻ������ظ�"));
		m_infoRight = false;
	}
	else if(m_infoRight)
	{
		ui.WarnLabel->clear();
	}
}

void SignUpWidget::SetEmailRepeatState(bool state)
{
	if (state == true)
	{
		m_inEmailRepeat = true;
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����ظ�"));
		m_infoRight = false;
	}
	else if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
}

void SignUpWidget::slot_CheckInfoFilled(QString str)
{
	//����û����Ƿ��ظ����Ƿ��зǷ��ַ����������Ƿ�ȫ������
	if (ui.NameEdit->text().contains("/") || ui.NameEdit->text().contains("\\") || ui.NameEdit->text().contains(" ") || ui.NameEdit->text().contains("-") || ui.NameEdit->text().contains("."))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û����к��зǷ��ַ�"));
		m_infoRight = false;
		return;
	}
	if (ui.NameEdit->text().length() > 16 || ui.NameEdit->text().length() < 3)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û������Ȳ�����Ҫ��"));
		m_infoRight = false;
		return;
	}
	if (ui.NameEdit->text().contains(QRegExp("^\\d+$")))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û�������ȫ������"));
		m_infoRight = false;
		return;
	}
	if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
	MainMessage m;
	Name_Repeat_Check *message_name = new Name_Repeat_Check();
	m.set_type(NAME_REPEAT_CHECK);
	message_name->set_name(ui.NameEdit->text().toStdString());
	m.set_allocated_content1(message_name);
	std::string msgStr;
	if (m.SerializeToString(&msgStr))
		//qDebug() << QString::fromLocal8Bit("���л����str") << QString::fromStdString(msgStr) + "\n";
	m.clear_content1();
	m.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	QThread::msleep(200);
	//����ֻ������Ƿ�11λ���Ƿ������֡��Ƿ��ظ�
	if (!ui.NumEdit->text().contains(QRegExp("^\\d+$")))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�ֻ����벻�Ϸ�"));
		m_infoRight = false;
		return;
	}
	if (ui.NumEdit->text().length() != 11)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�ֻ����벻�Ϸ�"));
		m_infoRight = false;
		return;
	}
	MainMessage m_number;
	Number_Repeat_Chexk* message_number = new Number_Repeat_Chexk();
	m_number.set_type(NUMBER_REPEAT_CHECK);
	message_number->set_number(ui.NumEdit->text().toStdString());
	m_number.set_allocated_content3(message_number);
	msgStr = "";
	if (m_number.SerializeToString(&msgStr))
		//qDebug() << QString::fromLocal8Bit("���л����str") << QString::fromStdString(msgStr) + "\n";
	m_number.clear_content3();
	m_number.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	QThread::msleep(200);
	if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
	//���email�Ƿ����Ҫ�� �ַ�ʹ�÷�Χ����@.���Ƿ��ظ�
	QString emailStr = ui.EmailEdit->text();
	if (!(emailStr.split("@").size() == 2 && emailStr.split(".").size() == 2 && emailStr.contains(".com") && (!emailStr.contains("@."))))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����ʽ���Ϸ�"));
		m_infoRight = false;
		return;
	}
	MainMessage m_email;
	Email_Repeat_Chexk* message_email = new Email_Repeat_Chexk();
	m_number.set_type(EMAIL_REPEAT_CHECK);
	message_email->set_email(ui.EmailEdit->text().toStdString());
	m_number.set_allocated_content5(message_email);
	msgStr = "";
	if (m_email.SerializeToString(&msgStr))
		//qDebug() << QString::fromLocal8Bit("���л����str") << QString::fromStdString(msgStr) + "\n";
		m_email.clear_content5();
	m_email.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	QThread::msleep(200);
	if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
	//�������1������2�Ƿ��зǷ��ַ����Ƿ���ȡ������Ƿ��㹻
	if (ui.PasswordEdit->text().contains("/") || ui.PasswordEdit->text().contains("\\") || ui.PasswordEdit->text().contains(" ") || ui.PasswordEdit->text().contains("-") || ui.PasswordEdit->text().contains("."))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����к��зǷ��ַ�"));
		m_infoRight = false;
		return;
	}
	if (ui.Password2Edit->text().contains("/") || ui.Password2Edit->text().contains("\\") || ui.Password2Edit->text().contains(" ") || ui.Password2Edit->text().contains("-") || ui.Password2Edit->text().contains("."))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����к��зǷ��ַ�"));
		m_infoRight = false;
		return;
	}
	if (ui.PasswordEdit->text() != ui.Password2Edit->text())
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("������������벻һ��"));
		m_infoRight = false;
		return;
	}

	//ui.WarnLabel->clear();
	m_infoRight = true;
	ui.WarnLabel->clear();
}
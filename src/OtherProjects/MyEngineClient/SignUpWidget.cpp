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
	if (!(img->load(filename))) //加载图像
	{
		QMessageBox::information(this,
			tr("打开图像失败"),
			tr("打开图像失败!"));
		delete img;
		return;
	}
	//ui.PixLabel->resize(400, 140); //设置label大小
	ui.PixLabel->setPixmap(QPixmap::fromImage(*img));
	//ui.label_2->setFixedSize(200, 40); //设置label大小
	//ui.PixLabel->move(30,30);
	ui.PixLabel->setScaledContents(true); //将pixmap图自适应填充到label
}

SignUpWidget::~SignUpWidget()
{}

void SignUpWidget::SetUserNameRepeatState(bool state)
{
	if (state == true)
	{
		m_inNameRepeat = true;
		ui.WarnLabel->setText(QString::fromLocal8Bit("用户名重复"));
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
		ui.WarnLabel->setText(QString::fromLocal8Bit("手机号码重复"));
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
		ui.WarnLabel->setText(QString::fromLocal8Bit("邮箱重复"));
		m_infoRight = false;
	}
	else if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
}

void SignUpWidget::slot_CheckInfoFilled(QString str)
{
	//检查用户名是否重复、是否含有非法字符、最短最长、是否全是数字
	if (ui.NameEdit->text().contains("/") || ui.NameEdit->text().contains("\\") || ui.NameEdit->text().contains(" ") || ui.NameEdit->text().contains("-") || ui.NameEdit->text().contains("."))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("用户名中含有非法字符"));
		m_infoRight = false;
		return;
	}
	if (ui.NameEdit->text().length() > 16 || ui.NameEdit->text().length() < 3)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("用户名长度不符合要求"));
		m_infoRight = false;
		return;
	}
	if (ui.NameEdit->text().contains(QRegExp("^\\d+$")))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("用户名不能全是数字"));
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
		//qDebug() << QString::fromLocal8Bit("序列化后的str") << QString::fromStdString(msgStr) + "\n";
	m.clear_content1();
	m.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	QThread::msleep(200);
	//检查手机号码是否11位、是否都是数字、是否重复
	if (!ui.NumEdit->text().contains(QRegExp("^\\d+$")))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("手机号码不合法"));
		m_infoRight = false;
		return;
	}
	if (ui.NumEdit->text().length() != 11)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("手机号码不合法"));
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
		//qDebug() << QString::fromLocal8Bit("序列化后的str") << QString::fromStdString(msgStr) + "\n";
	m_number.clear_content3();
	m_number.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	QThread::msleep(200);
	if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
	//检查email是否符合要求 字符使用范围、有@.、是否重复
	QString emailStr = ui.EmailEdit->text();
	if (!(emailStr.split("@").size() == 2 && emailStr.split(".").size() == 2 && emailStr.contains(".com") && (!emailStr.contains("@."))))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("邮箱格式不合法"));
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
		//qDebug() << QString::fromLocal8Bit("序列化后的str") << QString::fromStdString(msgStr) + "\n";
		m_email.clear_content5();
	m_email.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	QThread::msleep(200);
	if (m_infoRight)
	{
		ui.WarnLabel->clear();
	}
	//检查密码1和密码2是否含有非法字符，是否相等、长度是否足够
	if (ui.PasswordEdit->text().contains("/") || ui.PasswordEdit->text().contains("\\") || ui.PasswordEdit->text().contains(" ") || ui.PasswordEdit->text().contains("-") || ui.PasswordEdit->text().contains("."))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("密码中含有非法字符"));
		m_infoRight = false;
		return;
	}
	if (ui.Password2Edit->text().contains("/") || ui.Password2Edit->text().contains("\\") || ui.Password2Edit->text().contains(" ") || ui.Password2Edit->text().contains("-") || ui.Password2Edit->text().contains("."))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("密码中含有非法字符"));
		m_infoRight = false;
		return;
	}
	if (ui.PasswordEdit->text() != ui.Password2Edit->text())
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("两次输入的密码不一致"));
		m_infoRight = false;
		return;
	}

	//ui.WarnLabel->clear();
	m_infoRight = true;
	ui.WarnLabel->clear();
}
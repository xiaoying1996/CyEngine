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

	m_inNameRepeat = false;
}

SignUpWidget::~SignUpWidget()
{}

void SignUpWidget::SetUserNameRepeatState(bool state)
{
	if (state == false)
	{
		m_inNameRepeat = true;
	}
}

void SignUpWidget::slot_CheckInfoFilled(QString str)
{
	//检查用户名是否重复、是否含有非法字符、最短最长
	if (ui.NameEdit->text().contains("/") || ui.NameEdit->text().contains("\\") || ui.NameEdit->text().contains(" ") || ui.NameEdit->text().contains("-"))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("用户名中含有非法字符"));
		return;
	}
	MainMessage m;
	Name_Repeat_Check *message_name = new Name_Repeat_Check();
	m.set_type(NAME_REPEAT_CHECK);
	message_name->set_name(ui.NameEdit->text().toStdString());
	m.set_allocated_content1(message_name);
	std::string msgStr;
	if (m.SerializeToString(&msgStr))
		qDebug() << QString::fromLocal8Bit("序列化后的str") << QString::fromStdString(msgStr) + "\n";
	m.clear_content1();
	m.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	//检查手机号码是否11位、是否都是数字

	//检查email是否符合要求 字符使用范围、有@.

	//检查密码1和密码2是否含有非法字符，是否相等

	ui.WarnLabel->clear();
}
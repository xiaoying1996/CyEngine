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
	//����û����Ƿ��ظ����Ƿ��зǷ��ַ�������
	if (ui.NameEdit->text().contains("/") || ui.NameEdit->text().contains("\\") || ui.NameEdit->text().contains(" ") || ui.NameEdit->text().contains("-"))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û����к��зǷ��ַ�"));
		return;
	}
	MainMessage m;
	Name_Repeat_Check *message_name = new Name_Repeat_Check();
	m.set_type(NAME_REPEAT_CHECK);
	message_name->set_name(ui.NameEdit->text().toStdString());
	m.set_allocated_content1(message_name);
	std::string msgStr;
	if (m.SerializeToString(&msgStr))
		qDebug() << QString::fromLocal8Bit("���л����str") << QString::fromStdString(msgStr) + "\n";
	m.clear_content1();
	m.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
	//����ֻ������Ƿ�11λ���Ƿ�������

	//���email�Ƿ����Ҫ�� �ַ�ʹ�÷�Χ����@.

	//�������1������2�Ƿ��зǷ��ַ����Ƿ����

	ui.WarnLabel->clear();
}
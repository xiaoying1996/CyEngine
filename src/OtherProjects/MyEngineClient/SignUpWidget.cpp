#include "SignUpWidget.h"

SignUpWidget::SignUpWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QPalette label_pe;
	label_pe.setColor(QPalette::WindowText, Qt::red);
	ui.WarnLabel->setPalette(label_pe);
	connect(ui.NameEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckName(QString)));
	connect(ui.NumEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckNumber(QString)));
	connect(ui.EmailEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckEmail(QString)));
	connect(ui.PasswordEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckPassword(QString)));
	connect(ui.Password2Edit, SIGNAL(textChanged(QString)), this, SLOT(slot_CheckPassword(QString)));

	ui.PasswordEdit->setEchoMode(QLineEdit::Password);
	ui.Password2Edit->setEchoMode(QLineEdit::Password);


	m_inNameRepeat = true;
	m_inNumberRepeat = true;
	m_inEmailRepeat = true;
	m_isNameRight = false;
	m_isNumberRight = false;
	m_isEmailRight = false;
	m_isPasswordRight = false;

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
		m_inNameRepeat = false;
	}
	else {
		m_inNameRepeat = true;
	}
	SetErrorStr();
}

void SignUpWidget::SetNumberRepeatState(bool state)
{
	if (state == true)
	{
		m_inNumberRepeat = false;
	}
	else {
		m_inNumberRepeat = true;
	}
	SetErrorStr();
}

void SignUpWidget::SetEmailRepeatState(bool state)
{
	if (state == true)
	{
		m_inEmailRepeat = false;
	}
	else {
		m_inEmailRepeat = true;
	}
	SetErrorStr();
}

void SignUpWidget::SetErrorStr()
{
	ui.WarnLabel->clear();
	if(!m_isNameRight)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����û���")); return;
	}
	if (!m_isNumberRight)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����ֻ���")); return;
	}
	if (!m_isEmailRight)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("��������")); return;
	}
	if (!m_inNameRepeat)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û����ظ�")); return;
	}
	if (!m_inNumberRepeat)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�ֻ����ظ�")); return;
	}
	if (!m_inEmailRepeat)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����ظ�")); return;
	}
	if (!m_isPasswordRight)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("��ȷ������")); return;
	}
}

void SignUpWidget::ShowRegister(bool res)
{
	if (res)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ע��ɹ�"), QMessageBox::Close);
		ui.NameEdit->clear();
		ui.NumEdit->clear();
		ui.EmailEdit->clear();
		ui.PasswordEdit->clear();
		ui.Password2Edit->clear();
	}
	else {
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ע��ʧ��"), QMessageBox::Close);
	}
	return;
}

bool SignUpWidget::CheckErr()
{
	if (m_isNameRight && m_isNumberRight && m_isEmailRight && m_inNameRepeat && m_inNumberRepeat && m_inEmailRepeat && m_isPasswordRight)
	{
		return true;
	}
	return false;
}

void SignUpWidget::on_SureBtn_clicked()
{
	if (!CheckErr())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("ע����Ϣ��������"), QMessageBox::Close);
		return;
	}
	MainMessage m_register;
	Register_Request* message = new Register_Request();
	m_register.set_type(REGISTER_REQUEST);
	message->set_name(ui.NameEdit->text().toStdString());
	message->set_number(ui.NumEdit->text().toStdString());
	message->set_email(ui.EmailEdit->text().toStdString());
	message->set_password(ui.PasswordEdit->text().toStdString());
	m_register.set_allocated_content7(message);
	std::string msgStr = "";
	if (m_register.SerializeToString(&msgStr))
		//qDebug() << QString::fromLocal8Bit("���л����str") << QString::fromStdString(msgStr) + "\n";
		m_register.clear_content7();
	m_register.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
}

void SignUpWidget::slot_CheckName(QString str)
{
	//����û����Ƿ��ظ����Ƿ��зǷ��ַ����������Ƿ�ȫ������
	if (ui.NameEdit->text().contains("/") || ui.NameEdit->text().contains("\\") || ui.NameEdit->text().contains(" ") || ui.NameEdit->text().contains("-") || ui.NameEdit->text().contains("."))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û����к��зǷ��ַ�"));
		m_isNameRight = false;
		return;
	}
	if (ui.NameEdit->text().length() > 16 || ui.NameEdit->text().length() < 3)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û������Ȳ�����Ҫ��"));
		m_isNameRight = false;
		return;
	}
	if (ui.NameEdit->text().contains(QRegExp("^\\d+$")))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�û�������ȫ������"));
		m_isNameRight = false;
		return;
	}
	m_isNameRight = true;
	SetErrorStr();
	MainMessage m;
	Name_Repeat_Check *message_name = new Name_Repeat_Check();
	m.set_type(NAME_REPEAT_CHECK);
	message_name->set_name(ui.NameEdit->text().toStdString());
	m.set_allocated_content1(message_name);
	std::string msgStr;
	if (m.SerializeToString(&msgStr))
	m.clear_content1();
	m.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
}
void SignUpWidget::slot_CheckNumber(QString str)
{
	//����ֻ������Ƿ�11λ���Ƿ������֡��Ƿ��ظ�
	if (!ui.NumEdit->text().contains(QRegExp("^\\d+$")))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�ֻ����벻�Ϸ�"));
		m_isNumberRight = false;
		return;
	}
	if (ui.NumEdit->text().length() != 11)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�ֻ����볤�ȴ���"));
		m_isNumberRight = false;
		return;
	}
	m_isNumberRight = true;
	SetErrorStr();
	MainMessage m_number;
	Number_Repeat_Chexk* message_number = new Number_Repeat_Chexk();
	m_number.set_type(NUMBER_REPEAT_CHECK);
	message_number->set_number(ui.NumEdit->text().toStdString());
	m_number.set_allocated_content3(message_number);
	std::string msgStr = "";
	if (m_number.SerializeToString(&msgStr))
	m_number.clear_content3();
	m_number.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
}
void SignUpWidget::slot_CheckEmail(QString str)
{
	//���email�Ƿ����Ҫ�� �ַ�ʹ�÷�Χ����@.���Ƿ��ظ�
	QString emailStr = ui.EmailEdit->text();
	if (!(emailStr.split("@").size() == 2 && emailStr.split(".").size() == 2 && emailStr.contains(".com") && (!emailStr.contains("@."))))
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("�����ʽ���Ϸ�"));
		m_isEmailRight = false;
		return;
	}
	m_isEmailRight = true;
	SetErrorStr();
	MainMessage m_email;
	Email_Repeat_Chexk* message_email = new Email_Repeat_Chexk();
	m_email.set_type(EMAIL_REPEAT_CHECK);
	message_email->set_email(ui.EmailEdit->text().toStdString());
	m_email.set_allocated_content5(message_email);
	std::string msgStr = "";
	if (m_email.SerializeToString(&msgStr))
	m_email.clear_content5();
	m_email.Clear();
	MyTcpClient::GetInstance()->SendMessage(msgStr);
}

void SignUpWidget::slot_CheckPassword(QString str)
{
	if (ui.Password2Edit->text() != ui.PasswordEdit->text())
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("������������벻��ͬ"));
		m_isPasswordRight = false;
		return;
	}
	if (ui.PasswordEdit->text().length() < 8 || ui.PasswordEdit->text().length() > 32)
	{
		ui.WarnLabel->setText(QString::fromLocal8Bit("���볤�ȹ��������"));
		m_isPasswordRight = false;
		return;
	}
	m_isPasswordRight = true;
	SetErrorStr();
}
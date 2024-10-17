#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QPalette>
#include <QDebug>
#include <QString>
#include <QThread>
#include "MyTcpClient.h"
#include "MyEngineMessage.pb.h"
#include "ui_SignUpWidget.h"

using namespace LoginMessage;

class SignUpWidget : public QMainWindow
{
	Q_OBJECT

public:
	SignUpWidget(QWidget *parent = nullptr);
	~SignUpWidget();

	void SetUserNameRepeatState(bool state);
	void SetNumberRepeatState(bool state);
	void SetEmailRepeatState(bool state);
	void SetErrorStr();
	void ShowRegister(bool res);
	bool CheckErr();

public slots:
	void on_SureBtn_clicked();
	void slot_CheckName(QString str);
	void slot_CheckNumber(QString str);
	void slot_CheckEmail(QString str);
	void slot_CheckPassword(QString str);

private:
	Ui::SignInWidgetClass ui;
	bool m_inNameRepeat;
	bool m_inNumberRepeat;
	bool m_inEmailRepeat;
	bool m_isNameRight;
	bool m_isNumberRight;
	bool m_isEmailRight;
	bool m_isPasswordRight;
};

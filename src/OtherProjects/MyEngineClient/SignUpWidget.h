#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QPalette>
#include <QDebug>
#include <QString>
#include "MyEngineMessage.pb.h"
#include "ui_SignUpWidget.h"

using namespace LoginMessage;

class SignUpWidget : public QMainWindow
{
	Q_OBJECT

public:
	SignUpWidget(QWidget *parent = nullptr);
	~SignUpWidget();

public slots:
	void slot_CheckInfoFilled(QString str);

private:
	Ui::SignInWidgetClass ui;
};

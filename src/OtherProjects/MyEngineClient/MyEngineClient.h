#pragma once

#include <QtWidgets/QMainWindow>
#include <QPixMap>
#include <QMessageBox>
#include "MyTcpClient.h"
#include "PicPlayer.h"
#include "SignUpWidget.h"
#include "ui_MyEngineClient.h"

class MyEngineClient : public QMainWindow
{
    Q_OBJECT

public:
    MyEngineClient(QWidget *parent = nullptr);
    ~MyEngineClient();

public slots:
    void on_SignUpBtn_clicked();

private:
    Ui::MyEngineClientClass ui;
    PicPlayer* m_picPlayer = nullptr;
    SignUpWidget* m_signup = nullptr;
};

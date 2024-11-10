#pragma once

#include <QtWidgets/QMainWindow>
#include <QPixMap>
#include <QMessageBox>
#include <QTime>
#include "MyEngineMessage.pb.h"
#include "MyTcpClient.h"
#include "PicPlayer.h"
#include "SignUpWidget.h"
#include "HCLWidhet.h"
#include "ui_MyEngineClient.h"

class MyEngineClient : public QMainWindow
{
    Q_OBJECT

public:
    MyEngineClient(QWidget *parent = nullptr);
    ~MyEngineClient();

public slots:
    void on_SignUpBtn_clicked();
    void on_SignInBtn_clicked();

    void slot_ProcessTimeout();
    void slot_SignUpCLosed();

private:
    Ui::MyEngineClientClass ui;
    PicPlayer* m_picPlayer = nullptr;
    SignUpWidget* m_signup = nullptr;
    HCLWidhet* m_HCL = nullptr;
    QTimer* m_timer = nullptr;
};

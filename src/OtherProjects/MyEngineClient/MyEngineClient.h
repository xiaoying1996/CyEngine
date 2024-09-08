#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyEngineClient.h"

class MyEngineClient : public QMainWindow
{
    Q_OBJECT

public:
    MyEngineClient(QWidget *parent = nullptr);
    ~MyEngineClient();

private:
    Ui::MyEngineClientClass ui;
};

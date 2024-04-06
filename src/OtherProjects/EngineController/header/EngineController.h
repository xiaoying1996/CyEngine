#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_EngineController.h"
#include "../../../Engine/MyEngine.h"
#include "../../../Public/PublicInclude.h"
#include "../../../Service/LogReport/LogReport.h"

class EngineController : public QMainWindow
{
    Q_OBJECT

public:
    EngineController(QWidget *parent = Q_NULLPTR);

public slots:
    void on_StartBtn_clicked();
    void slot_ThreadModeChanged(QString str);

private:
    Ui::EngineControllerClass ui;
    MyEngine *engine = nullptr;
};

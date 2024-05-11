#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include "ui_EngineController.h"
#include "Engine/MyEngine.h"
#include "Public/PublicInclude.h"
#include "Service/LogReport/LogReport.h"
#include "Models/Human/People/People.h"

class EngineController : public QMainWindow
{
    Q_OBJECT

public:
    EngineController(QWidget *parent = Q_NULLPTR);

public slots:
    void on_StartBtn_clicked();
    void on_StopBtn_clicked();
    void on_TestBtn_clicked();
    void on_ReadScenarioBtn_clicked();
    void slot_ThreadModeChanged(QString str);
    void slot_update();

private:
    Ui::EngineControllerClass ui;
    MyEngine *engine = nullptr;
    QTimer* timer = nullptr;
};

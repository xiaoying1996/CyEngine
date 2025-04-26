#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include "ui_EngineController.h"
#include "Service/LogReport/LogReport.h"
#include "Models/Human/People/People.h"
#include "MissionChooser.h"

class EngineController : public QMainWindow
{
    Q_OBJECT

public:
    EngineController(QWidget *parent = Q_NULLPTR);
    void InitModelsTree();      //对展示模型数据信息的树形图进行初始化

public slots:
    void on_StartBtn_clicked();
    void on_StopBtn_clicked();
    void on_TestBtn_clicked();
    void on_ReadScenarioBtn_clicked();
    void on_UpdateBtn_clicked();
    void on_SendMissionBtn_clicked();
    void slot_ThreadModeChanged(QString str);
    void slot_update();
    void slot_CheckEngineStatus();

private:
    Ui::EngineControllerClass ui;
    MyEngine *engine = nullptr;
    QTimer* timer = nullptr;
    QTimer* timer2 = nullptr;

    MissionChooser* missionChooser;

    EngineStatus m_EngineStu;
    bool m_isEngineReadScenario;
    bool m_isStart;
};

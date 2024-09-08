#ifndef _ENGINE_CONTROLLER_
#define _ENGINE_CONTROLLER_

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "../header/EngineController.h"
#include "../../../Engine/MyEngine.h"
#include "../../../Public/PublicInclude.h"
#include "../../../Service/LogReport/LogReport.h"
#include "../../../Models//Human//People/People.h"
#include <ui_EngineController.h>

class EngineController : public QMainWindow
{
    Q_OBJECT

public:
    EngineController(QWidget *parent = Q_NULLPTR);

public slots:
    void on_StartBtn_clicked();
    void on_StopBtn_clicked();
    void on_TestBtn_clicked();
    void slot_ThreadModeChanged(QString str);
    void slot_update();

private:
    Ui::EngineControllerClass ui;
    MyEngine *engine = nullptr;
    QTimer* timer = nullptr;
};

#endif
#include "../header/EngineController.h"

EngineController::EngineController(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    engine = MyEngine::GetInstance();
    ui.label_2->hide();
    ui.label_3->hide();
    ui.MaxThreadBox->hide();
    ui.MinThreadBox->hide();
    ui.StopBtn->setDisabled(true);
    connect(ui.ThreadModePoolBox, SIGNAL(currentIndexChanged(QString)),this, SLOT(slot_ThreadModeChanged(QString)));
}

void EngineController::on_StartBtn_clicked()
{
    if (engine == nullptr)
    {
        engine = MyEngine::GetInstance();
    }
    QString threadMode = ui.ThreadModePoolBox->currentText();
    if (threadMode == QString::fromLocal8Bit("单线程"))
    {
        ErrorState err = engine->Init(1, 1);
        _LOG->PrintError(err);
        ui.StartBtn->setDisabled(true);
        ui.StopBtn->setDisabled(false);
    }if (threadMode == QString::fromLocal8Bit("多线程"))
    {
        int min = ui.MinThreadBox->currentText().toInt();
        int max = ui.MaxThreadBox->currentText().toInt();
        if (min > max)
        {
            QMessageBox::information(this, "Info", "MinThread Num More Than MaxThread Num", QMessageBox::Close);
        }
        else {
            ErrorState err = engine->Init(min, max);
            _LOG->PrintError(err);
        }
        ui.StartBtn->setDisabled(true);
        ui.StopBtn->setDisabled(false);
    }
    timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_update()));
}

void EngineController::on_StopBtn_clicked()
{
    ui.StartBtn->setDisabled(false);
    ui.StopBtn->setDisabled(true);
    disconnect(timer, SIGNAL(timeout()), this, SLOT(slot_update()));
    timer->stop();
    if (engine != nullptr)
    {
        delete engine;
        engine = nullptr;
    }
    ui.AliveEdit->setText(QString::number(0));
    ui.CurrentEdit->setText(QString::number(0));
}

void EngineController::slot_ThreadModeChanged(QString str)
{
    if (str == QString::fromLocal8Bit("单线程"))
    {
        ui.label_2->hide();
        ui.label_3->hide();
        ui.MaxThreadBox->hide();
        ui.MinThreadBox->hide();
    }
    else if (str == QString::fromLocal8Bit("多线程"))
    {
        ui.label_2->show();
        ui.label_3->show();
        ui.MaxThreadBox->show();
        ui.MinThreadBox->show();
    }
}

void EngineController::slot_update()
{
    int alive = 0, busy= 0;
    if (engine)
    {
        engine->GetInstance()->GetThreadNum(alive,busy);
    }
    ui.AliveEdit->setText(QString::number(alive));
    ui.CurrentEdit->setText(QString::number(busy));
}
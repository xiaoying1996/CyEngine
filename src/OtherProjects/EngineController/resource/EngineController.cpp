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
    connect(ui.ThreadModePoolBox, SIGNAL(currentIndexChanged(QString)),this, SLOT(slot_ThreadModeChanged(QString)));
}

void EngineController::on_StartBtn_clicked()
{
    QString threadMode = ui.ThreadModePoolBox->currentText();
    if (threadMode == QString::fromLocal8Bit("���߳�"))
    {
        ErrorState err = engine->Init(1, 1);
        _LOG->PrintError(err);
        ui.StartBtn->setDisabled(true);
    }if (threadMode == QString::fromLocal8Bit("���߳�"))
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
    }
}

void EngineController::slot_ThreadModeChanged(QString str)
{
    if (str == QString::fromLocal8Bit("���߳�"))
    {
        ui.label_2->hide();
        ui.label_3->hide();
        ui.MaxThreadBox->hide();
        ui.MinThreadBox->hide();
    }
    else if (str == QString::fromLocal8Bit("���߳�"))
    {
        ui.label_2->show();
        ui.label_3->show();
        ui.MaxThreadBox->show();
        ui.MinThreadBox->show();
    }
}
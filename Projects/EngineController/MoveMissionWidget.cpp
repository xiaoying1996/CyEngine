#include "MoveMissionWidget.h"

MoveMissionWidget::MoveMissionWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    choosedModelName = "";
    connect(ui.HumanBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onHumanComboxSelect(int)));
    connect(ui.UavBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onUavComboxSelect(int)));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MoveMissionWidget::timeout);
}

MoveMissionWidget::~MoveMissionWidget()
{}

void MoveMissionWidget::SetExecuter()
{
    models.clear();
	MyEngine::GetInstance()->GetAllModels(models);
    ui.HumanBox->clear();
    ui.UavBox->clear();
    for (int i = 0; i < models.size(); i++)
    {
        switch (models[i]._type)
        {
        case ModelType::M_PEOPLE:
        {
            ui.HumanBox->addItem(QString::fromLocal8Bit(models[i]._name));
            break;
        }
        case ModelType::M_OPTICALATTACKUAV:
        {
            ui.UavBox->addItem(QString::fromLocal8Bit(models[i]._name));
            break;
        }
        default:
            break;
        }
    }
}

void MoveMissionWidget::on_SendBtn_clicked()
{
    auto mission = std::make_shared<Mission_Move>();
    for (int i = 0; i < ui.MoveListWidget->rowCount(); i++) {
        Model_Position point;
        for (int j = 0; j < ui.MoveListWidget->columnCount(); j++) 
        {
            if (ui.MoveListWidget->item(i, j) != NULL) {
                if (j == 0)
                {
                    point._lon =  ui.MoveListWidget->item(i,j)->text().toDouble();
                }
                else if (j == 1)
                {
                    point._lat = ui.MoveListWidget->item(i, j)->text().toDouble();
                }
                else if (j == 2)
                {
                    point._alt = ui.MoveListWidget->item(i, j)->text().toDouble();
                }
            }
        }
        if (point._lon != 0 && point._lat != 0 && point._alt != 0)
        {
            mission->moveList.push_back(point);
        }
    }
    int modelID = 0;
    for (int i = 0; i < models.size(); i++)
    {
        if (choosedModelName == models[i]._name)
        {
            modelID = models[i]._id;
        }
    }
    mission->receicerID = modelID;
    MyEngine::GetInstance()->PutEvent(mission);
    timer->start(100);
}

void MoveMissionWidget::onHumanComboxSelect(int index)
{
    choosedModelName = ui.HumanBox->currentText().toLocal8Bit();
    ui.ExecuterEdit->setText(ui.HumanBox->currentText());
}
void MoveMissionWidget::onUavComboxSelect(int index)
{
    choosedModelName = ui.UavBox->currentText().toLocal8Bit();
    ui.ExecuterEdit->setText(ui.UavBox->currentText());
}

void MoveMissionWidget::timeout()
{
    int modelID = 0;
    for (int i = 0; i < models.size(); i++)
    {
        if (choosedModelName == models[i]._name)
        {
            modelID = models[i]._id;
        }
    }
    Model_BasicInfo info;
    MyEngine::GetInstance()->GetModelByID(info,modelID);
    ui.LonEdit->setText(QString::number(info._pos._lon ,'d',8));
    ui.LatEdit->setText(QString::number(info._pos._lat, 'd', 8));
    ui.AltEdit->setText(QString::number(info._pos._alt, 'd', 8));
}
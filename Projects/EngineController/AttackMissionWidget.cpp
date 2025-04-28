#include "AttackMissionWidget.h"
#include "Engine/MyEngine.h"
#include <QCheckBox>

AttackMissionWidget::AttackMissionWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    TypeMap[M_PEOPLE] = QString::fromLocal8Bit("人员");
    TypeMap[M_OPTICALATTACKUAV] = QString::fromLocal8Bit("可见光无人机");
    connect(ui.HumanBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onHumanComboxSelect(int)));
    connect(ui.UavBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onUavComboxSelect(int)));
    choosedModelName = "";
}

AttackMissionWidget::~AttackMissionWidget()
{}

void AttackMissionWidget::SetExecuter()
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
            ui.HumanBox->addItem(QString::fromLocal8Bit(models[i]._name.c_str()));
            break;
        }
        case ModelType::M_OPTICALATTACKUAV:
        {
            ui.UavBox->addItem(QString::fromLocal8Bit(models[i]._name.c_str()));
            break;
        }
        default:
            break;
        }
    }
    ui.TargetListWidget->setRowCount(models.size());
    ui.TargetListWidget->setColumnCount(5);
    QHeaderView* header = ui.TargetListWidget->verticalHeader();
    header->setHidden(true);// 隐藏行号

    QStringList headerText;
    headerText << "ID" << QString::fromLocal8Bit("阵营") << QString::fromLocal8Bit("类型")<< QString::fromLocal8Bit("名称") << QString::fromLocal8Bit("选择");
    ui.TargetListWidget->setHorizontalHeaderLabels(headerText);
    ui.TargetListWidget->setColumnWidth(0, 70);
    ui.TargetListWidget->setColumnWidth(1, 100);
    ui.TargetListWidget->setColumnWidth(2, 100);
    ui.TargetListWidget->setColumnWidth(3, 300);
    ui.TargetListWidget->setColumnWidth(4, 80);
    for (int i = 0; i < models.size(); i++)
    {
        ui.TargetListWidget->setItem(i, 0, new QTableWidgetItem(QString::number(models[i]._id)));
        ui.TargetListWidget->setItem(i, 1, new QTableWidgetItem(QString::number(models[i]._camp)));
        ui.TargetListWidget->setItem(i, 2, new QTableWidgetItem(TypeMap[(ModelType)models[i]._type]));
        ui.TargetListWidget->setItem(i, 3, new QTableWidgetItem(QString::fromLocal8Bit(models[i]._name.data())));
        QCheckBox *ckBox = new QCheckBox(ui.TargetListWidget);
        ckBox->setChecked(false);
        ui.TargetListWidget->setCellWidget(i, 4, ckBox);
    }
}

void AttackMissionWidget::onHumanComboxSelect(int index)
{
    choosedModelName = ui.HumanBox->currentText().toLocal8Bit();
    ui.ExecuterEdit->setText(ui.HumanBox->currentText());
}
void AttackMissionWidget::onUavComboxSelect(int index)
{
    choosedModelName = ui.UavBox->currentText().toLocal8Bit();
    ui.ExecuterEdit->setText(ui.UavBox->currentText());
}

void AttackMissionWidget::on_SendBtn_clicked()
{
    Mission_Attack* mission = new Mission_Attack();
    int modelID = 0;
    for (int i = 0; i < models.size(); i++)
    {
        if (choosedModelName == models[i]._name)
        {
            modelID = models[i]._id;
        }
    }
    mission->receicerID = modelID;
    for (int i = 0; i < ui.TargetListWidget->rowCount(); i++) 
    {
        QCheckBox* box = dynamic_cast<QCheckBox*> (ui.TargetListWidget->cellWidget(i,4));
        if(box->checkState())
        {
            mission->targets.push_back(ui.TargetListWidget->item(i, 0)->text().toInt());
        }
    }
    if (mission->targets.size())
    {
        mission->attackMode = 2;
    }
    else
    {
        mission->attackMode = 1;
    }
    MyEngine::GetInstance()->PutEvent(mission);
}
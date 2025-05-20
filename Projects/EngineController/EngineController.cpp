#include "EngineController.h"

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
    ui.StartBtn->setDisabled(true);
    ui.SendMissionBtn->setDisabled(true);
    connect(ui.ThreadModePoolBox, SIGNAL(currentIndexChanged(QString)),this, SLOT(slot_ThreadModeChanged(QString)));

    m_EngineStu = EN_NOSTU;
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(slot_CheckEngineStatus()));
    timer2->start(1000);
    //一开始，设置没读取想定数据
    m_isEngineReadScenario = false;
    m_isStart = false;
    //初始化模型列表树形图
    InitModelsTree();
    missionChooser = nullptr;
}

void EngineController::InitModelsTree()
{
    ui.ModelsListTree->setColumnCount(1);
    QTreeWidgetItem *topItemhuman = new QTreeWidgetItem();
    topItemhuman->setText(0, QString::fromLocal8Bit("人员"));
    QTreeWidgetItem* topItemuav = new QTreeWidgetItem();
    topItemuav->setText(0, QString::fromLocal8Bit("无人机"));
    QTreeWidgetItem* topItemvehicle = new QTreeWidgetItem();
    topItemvehicle->setText(0, QString::fromLocal8Bit("车辆"));
    ui.ModelsListTree->addTopLevelItem(topItemhuman);
    ui.ModelsListTree->addTopLevelItem(topItemuav);
    ui.ModelsListTree->addTopLevelItem(topItemvehicle);
    int count = ui.ModelsListTree->topLevelItemCount();
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
        ErrorState err = engine->GetInstance()->Init(1, 1);
        _LOG->PrintError(err);
        ui.StartBtn->setDisabled(true);
        ui.StopBtn->setDisabled(false);
        ui.SendMissionBtn->setDisabled(false);
    }if (threadMode == QString::fromLocal8Bit("多线程"))
    {
        int min = ui.MinThreadBox->currentText().toInt();
        int max = ui.MaxThreadBox->currentText().toInt();
        if (min > max)
        {
            QMessageBox::information(this, "Info", "MinThread Num More Than MaxThread Num", QMessageBox::Close);
        }
        else {
            ErrorState err = engine->GetInstance()->Init(min, max);
            _LOG->PrintError(err);
        }
        ui.StartBtn->setDisabled(true);
        ui.StopBtn->setDisabled(false);
        ui.SendMissionBtn->setDisabled(false);
    }
    if (timer == nullptr)
    {
        timer = new QTimer(this);
    }
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_update()));
}

void EngineController::on_StopBtn_clicked()
{
    ui.StartBtn->setDisabled(false);
    ui.StopBtn->setDisabled(true);
    ui.SendMissionBtn->setDisabled(true);
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

void EngineController::on_TestBtn_clicked()
{
    ////测试people
    //HINSTANCE hDll = LoadLibrary(L"Peopled.dll");
    //if (hDll == NULL)
    //{
    //    std::cout << "Load dll failed!";
    //    return ;
    //}
    //using functionPtr = People*(*)();
    //functionPtr addFunction = (functionPtr)GetProcAddress(hDll, "CreateModel");
    //if (addFunction == NULL)
    //{
    //    std::cout << "cannot find target function!";
    //    return ;
    //}

    //ModelBase*model =  addFunction();
}

void EngineController::on_ReadScenarioBtn_clicked()
{
    QString FilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择想定文件"), "./", "Scenarios(*.xml)");
    if (engine == nullptr)
    {
        engine = MyEngine::GetInstance();
    }
    std::string errStr;
    MyEngine::GetInstance()->ReadScenario(FilePath.toLocal8Bit().data(), errStr);
}

void EngineController::on_UpdateBtn_clicked()
{
    std::vector<Model_BasicInfo> models;
    MyEngine::GetInstance()->GetAllModels(models);
    int count = ui.ModelsListTree->topLevelItemCount();
    QTreeWidgetItem* humanItem = nullptr;
    QTreeWidgetItem* uavItem = nullptr;
    QTreeWidgetItem* vehicleItem = nullptr;
    for (int index = 0; index < count; index++)
    {
        QTreeWidgetItem *item = ui.ModelsListTree->topLevelItem(index);
        if (item->text(0) == QString::fromLocal8Bit("人员"))
        {
            humanItem = item;
            humanItem->setExpanded(true);
            humanItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
            qDeleteAll(humanItem->takeChildren());

        }
        else if (item->text(0) == QString::fromLocal8Bit("无人机"))
        {
            uavItem = item;
            uavItem->setExpanded(true);
            uavItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
            qDeleteAll(uavItem->takeChildren());
        }
        else if (item->text(0) == QString::fromLocal8Bit("车辆"))
        {
            vehicleItem = item;
            vehicleItem->setExpanded(true);
            vehicleItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
            qDeleteAll(vehicleItem->takeChildren());
        }
    }

    for (int i = 0; i < models.size(); i++)
    {
        switch (models[i]._type)
        {
        case ModelType::M_PEOPLE:case M_ASSULTMAN:case M_SNIPER:
        {
            if (humanItem != nullptr)
            {
                QTreeWidgetItem* humanItemSub = new QTreeWidgetItem(humanItem);
                humanItemSub->setText(0, QString::fromLocal8Bit(models[i]._name));
                humanItem->addChild(humanItemSub);
                //类型、坐标、id
                QTreeWidgetItem* humanItemSub_Type = new QTreeWidgetItem(humanItemSub);
                humanItemSub_Type->setText(0,QString::fromLocal8Bit("类型:人员"));
                humanItemSub->addChild(humanItemSub_Type);
                QTreeWidgetItem* humanItemSub_Pos = new QTreeWidgetItem(humanItemSub);
                humanItemSub_Pos->setText(0, QString::fromLocal8Bit("位置"));
                humanItemSub->addChild(humanItemSub_Pos);
                QTreeWidgetItem* humanItemSub_Pos_X = new QTreeWidgetItem(humanItemSub_Pos);
                humanItemSub_Pos_X->setText(0, QString::fromLocal8Bit("X:") + QString::number(models[i]._pos._lon));
                humanItemSub_Pos->addChild(humanItemSub_Pos_X);
                QTreeWidgetItem* humanItemSub_Pos_Y = new QTreeWidgetItem(humanItemSub_Pos);
                humanItemSub_Pos_Y->setText(0, QString::fromLocal8Bit("Y:") + QString::number(models[i]._pos._lat));
                humanItemSub_Pos->addChild(humanItemSub_Pos_Y);
                QTreeWidgetItem* humanItemSub_Pos_Z = new QTreeWidgetItem(humanItemSub_Pos);
                humanItemSub_Pos_Z->setText(0, QString::fromLocal8Bit("Z:") + QString::number(models[i]._pos._alt));
                humanItemSub_Pos->addChild(humanItemSub_Pos_Z);
            }
            break;
        }
        case ModelType::M_OPTICALATTACKUAV:case M_GRENADEDRONE:case M_MISSILEDRONE:case M_OPTICALINFRAREDDRONE:case M_COMPOSITEWINGDRONE:
        {
            if (uavItem != nullptr)
            {
                QTreeWidgetItem* uavItemSub = new QTreeWidgetItem(uavItem);
                uavItemSub->setText(0, QString::fromLocal8Bit(models[i]._name));
                uavItem->addChild(uavItemSub);
                //类型、坐标、id
                QTreeWidgetItem* uavItemSub_Type = new QTreeWidgetItem(uavItemSub);
                uavItemSub_Type->setText(0, QString::fromLocal8Bit("类型:无人机"));
                uavItemSub->addChild(uavItemSub_Type);
                QTreeWidgetItem* uavItemSub_Pos = new QTreeWidgetItem(uavItemSub);
                uavItemSub_Pos->setText(0, QString::fromLocal8Bit("位置"));
                uavItemSub->addChild(uavItemSub_Pos);
                QTreeWidgetItem* uavItemSub_Pos_X = new QTreeWidgetItem(uavItemSub_Pos);
                uavItemSub_Pos_X->setText(0, QString::fromLocal8Bit("X:") + QString::number(models[i]._pos._lon));
                uavItemSub_Pos->addChild(uavItemSub_Pos_X);
                QTreeWidgetItem* uavItemSub_Pos_Y = new QTreeWidgetItem(uavItemSub_Pos);
                uavItemSub_Pos_Y->setText(0, QString::fromLocal8Bit("Y:") + QString::number(models[i]._pos._lat));
                uavItemSub_Pos->addChild(uavItemSub_Pos_Y);
                QTreeWidgetItem* uavItemSub_Pos_Z = new QTreeWidgetItem(uavItemSub_Pos);
                uavItemSub_Pos_Z->setText(0, QString::fromLocal8Bit("Z:") + QString::number(models[i]._pos._alt));
                uavItemSub_Pos->addChild(uavItemSub_Pos_Z);
            }
            break;
        }
        case ModelType::M_GROUNDASSULTUNMANVEHICLE:case M_JEEP:case M_CM33:case M_GUARANTEEVEHICLE:
        {
            if (vehicleItem != nullptr)
            {
                QTreeWidgetItem* vehicleItemSub = new QTreeWidgetItem(vehicleItem);
                vehicleItemSub->setText(0, QString::fromLocal8Bit(models[i]._name));
                vehicleItem->addChild(vehicleItemSub);
                //类型、坐标、id
                QTreeWidgetItem* vehicleItemSub_Type = new QTreeWidgetItem(vehicleItemSub);
                vehicleItemSub_Type->setText(0, QString::fromLocal8Bit("类型:车辆"));
                vehicleItemSub->addChild(vehicleItemSub_Type);
                QTreeWidgetItem* vehicleItemSub_Pos = new QTreeWidgetItem(vehicleItemSub);
                vehicleItemSub_Pos->setText(0, QString::fromLocal8Bit("位置"));
                vehicleItemSub->addChild(vehicleItemSub_Pos);
                QTreeWidgetItem* vehicleItemSub_Pos_X = new QTreeWidgetItem(vehicleItemSub_Pos);
                vehicleItemSub_Pos_X->setText(0, QString::fromLocal8Bit("X:") + QString::number(models[i]._pos._lon));
                vehicleItemSub_Pos->addChild(vehicleItemSub_Pos_X);
                QTreeWidgetItem* vehicleItemSub_Pos_Y = new QTreeWidgetItem(vehicleItemSub_Pos);
                vehicleItemSub_Pos_Y->setText(0, QString::fromLocal8Bit("Y:") + QString::number(models[i]._pos._lat));
                vehicleItemSub_Pos->addChild(vehicleItemSub_Pos_Y);
                QTreeWidgetItem* vehicleItemSub_Pos_Z = new QTreeWidgetItem(vehicleItemSub_Pos);
                vehicleItemSub_Pos_Z->setText(0, QString::fromLocal8Bit("Z:") + QString::number(models[i]._pos._alt));
                vehicleItemSub_Pos->addChild(vehicleItemSub_Pos_Z);
            }
            break;
        }
        default:
            break;
        }
    }
}

void EngineController::on_SendMissionBtn_clicked()
{
    if (missionChooser == nullptr)
    {
        missionChooser = new MissionChooser();
        missionChooser->show();
    }
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

void EngineController::slot_CheckEngineStatus()
{
    if (!m_isEngineReadScenario)
    {
        m_isEngineReadScenario = MyEngine::GetInstance()->GetScenarioReadStu();
        if (m_isEngineReadScenario)
        {
            ui.StartBtn->setDisabled(false);
            m_EngineStu = EN_READSEC;
        }
    }
    else
    {
        m_isStart = MyEngine::GetInstance()->GetStartStu();
        if (m_isStart)
        {
            //如果引擎已经启动，定时向引擎内更新当前的实体信息
            //这里还有问题，因为还没有写针对所有实体进行消息发送的逻辑，后面还要写公布订购
            // 所以这里等上面完善了再处理这里
            //if (m_EngineStu == EN_READSEC)
            //{
            //    std::vector<Model_BasicInfo> models;
            //    MyEngine::GetInstance()->GetAllModels(models);
            //    Message_ModelsInfoAll* message = new Message_ModelsInfoAll();
            //    message->receicerID = 0;//0代表发给所有人
            //    message->modelsInfoList = models;
            //    MyEngine::GetInstance()->PutEvent(message);
            //}
        }
    }
}
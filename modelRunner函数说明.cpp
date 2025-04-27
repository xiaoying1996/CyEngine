//这是模型运行的主要逻辑，是开线程运行的，在Engine创建线程池时可以设置线程数量
//目前基本时单线程，也就是创建一个线程，多线程逻辑上可以用，但是我一般都是跑单线程
//也不是说一定要用这个引擎，这个引擎只是提供了调用这些模型的一个方法

void ModelRunner(void* arg)
{
    static time_t tickStart;
    time_t tickFinish;
    bool isPrintTick = false;;
    while (true)
    {
        if (MyEngine::GetInstance()->GetAdvanceStu() == ADV_FINISH)//这个判断的意思是在一个时间步长里面所有的模型都已经执行完了Run函数
        {
            if (!isPrintTick)
            {
                tickFinish = GetCurrentTimeMsec();
                _LOG->PrintError("战斗时间:" + to_string(MyEngine::GetInstance()->GetBattleTime()) + "  该Tick耗时:" + to_string(tickFinish - tickStart));
                isPrintTick = true;
            }
            continue;
        }
        if (MyEngine::GetInstance()->GetAdvanceStu() == ADV_READY)//这个判断是说将所有执行完毕的模型放入了待运行的列表中
        {
            MyEngine::GetInstance()->SetAdvanceStu(ADV_RUNNING);
            isPrintTick = false;
            tickStart = GetCurrentTimeMsec();
        }
        //走到这就证明时间状态未RUNNING，执行以下工作
        /*
        1.从ReadyVec中读取一个model，将其移到RunningVec中
        */
        ModelBase* model = ModelManager::GetInstance()->GetModelForRunn();//在待运行的列表中获取一个模型准备运行
        if (model == nullptr)//ReadyVec已经为空了
        {
            //判断RunningVec是否为空，若为空，将时间状态设置为结束
            if (ModelManager::GetInstance()->Is_model_Running_Vec_Empty())
            {
                MyEngine::GetInstance()->SetAdvanceStu(ADV_FINISH);
            }
        }
        else//拿到了要运行的模型，1.将其放入RunningVec 2.执行运行任务
        {
            ModelManager::GetInstance()->AddModelToRunningVec(model);
            //遍历当前暂存的事件数据，推给模型
            Model_BasicInfo info;
            model->GetBasicInfo(info);
            vector<EventBase*> events = MyEngine::GetInstance()->GetEvents(info._id);//引擎收到了一些事件会存起来，存起来之后在这里可以拿到
            for (int i = 0; i < events.size(); i++)
            {
                model->ReceiveEvent(events[i]);//将拿到的事件推给模型给模型处理
                model->PutEventToComponent();//将拿到的组件推给模型里面的组件
                delete events[i];//等模型和它的组件将该事件处理完事之后销毁掉
            }
            model->Run(0);//执行模型的run函数，在这里会在模型的基类中执行组件的run函数，然后执行子类里面的run函数
            //执行结束后，将其从RunningVec转移到FinishVec
            ModelManager::GetInstance()->MoveModelFromRunningToFinish(model);//然后将模型放入执行结束模型的列表
        }
    }
}
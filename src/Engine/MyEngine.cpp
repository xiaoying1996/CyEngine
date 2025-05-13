#include "MyEngine.h"
#include "Public/ServiceInterShareMemoryDefs.h"

MyEngine* MyEngine::m_MyEngine = nullptr;
std::mutex MyEngine::m_Mutex;
std::mutex MyEngine::m_Mutex_Advance;

void ModelRunner(void* arg)
{
    static time_t tickStart;
    time_t tickFinish;
    bool isPrintTick = false;;
    while (true)
    {
        if (MyEngine::GetInstance()->GetAdvanceStu() == ADV_FINISH)
        {
            if (!isPrintTick)
            {
                tickFinish = GetCurrentTimeMsec();
                _LOG->PrintError("战斗时间:" + to_string(MyEngine::GetInstance()->GetBattleTime()) + "  该Tick耗时:" + to_string(tickFinish - tickStart));
                isPrintTick = true;
            }
            continue;
        }
        if (MyEngine::GetInstance()->GetAdvanceStu() == ADV_READY)
        {
            MyEngine::GetInstance()->SetAdvanceStu(ADV_RUNNING);
            isPrintTick = false;
            tickStart = GetCurrentTimeMsec();
        }
        //走到这就证明时间状态未RUNNING，执行以下工作
        /*
        1.从ReadyVec中读取一个model，将其移到RunningVec中
        */
        ModelBase* model = ModelManager::GetInstance()->GetModelForRunn();
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
            vector<EventBase*> events = MyEngine::GetInstance()->GetEvents(info._id);
            for (int i = 0; i < events.size(); i++)
            {
                model->ReceiveEvent(events[i]);
                model->PutEventToComponent();
                //delete events[i];
            }
            if (events.size() > 1)
            {
                for (int i = 0; i < events.size(); i++)
                {
                    delete events[i];
                }
            }
            else if (events.size() == 1)
            {
                delete events[0];
            }

            model->Run(0);
            //在模型运行完成以后，将产生的事件提取出来
            std::vector<EventBase*> eventsFromModel = model->HandleEvent();
            for (int i = 0; i < eventsFromModel.size(); i++)
            {
                MyEngine::GetInstance()->PutEvent((eventsFromModel[i]));
            }

            //执行结束后，将其从RunningVec转移到FinishVec
            ModelManager::GetInstance()->MoveModelFromRunningToFinish(model);
        }
    }
}

void TimeAdvanceManager(void* arg)
{
    //在这里设置时间就绪，条件时间状态为处理完成，处理完成设置是模型处理线程处理完模型相关函数后判断待处理的模型为空，并将所有模型放入了处理完毕列表
    //设置时间就绪时，同样要将处理完的模型放进待处理列表
    while (true)
    {
        Sleep(100);
        if (MyEngine::GetInstance()->GetAdvanceStu() == ADV_FINISH)
        {
            int i = 0;
            //1.将所有已完成容器里面的模型放入ReadyVec中
            ModelManager::GetInstance()->MoveAllModelsFromFinishToReady();
            //2.将时间状态设置为Ready
            MyEngine::GetInstance()->SetAdvanceStu(ADV_READY);
            MyEngine::GetInstance()->OperatService();
            MyEngine::GetInstance()->BattleTimeAdvance();
        }
        else
        {
            _LOG->PrintError("时间管理线程，当前时间未达到就绪状态，还有模型未执行完毕，等待下一个脉冲");
        }
    }
    int i = 1;
}

MyEngine* MyEngine::GetInstance()
{
    if (m_MyEngine == nullptr)
    {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (m_MyEngine == nullptr)
        {
            m_MyEngine = new (std::nothrow) MyEngine();
        }
    }
    return m_MyEngine;
}

void MyEngine::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex);
    if (m_MyEngine)
    {
        delete m_MyEngine;
        m_MyEngine = nullptr;
    }
}

MyEngine::MyEngine()
{
    #if _DEBUG
        _LOG->PrintError("引擎执行构造");
    #endif // NDEBUG

    m_pool = nullptr;
    m_isScenarioRead = false;
    m_isStart = false;
    m_battleTime = 0;
    _serviceInterface = ServiceInterface::GetInstance();
    #if _DEBUG
        _LOG->PrintError("引擎构造完成");
    #endif // NDEBUG
}

MyEngine::MyEngine(const MyEngine& manager)
{

}

MyEngine::~MyEngine()
{
    #if _DEBUG
        _LOG->PrintError("引擎开始析构");
    #endif // NDEBUG
    //销毁线程池
    if (m_pool)
    {
        delete m_pool;
        m_pool = nullptr;
    }
    //等待时间管理线程结束
    m_TimeAdvancer_Thread->join();
    //销毁模型管理器
    ModelManager::deleteInstance();
    m_MyEngine = nullptr;
    #if _DEBUG
        _LOG->PrintError("引擎析构完成");
    #endif // NDEBUG
}

ErrorState MyEngine::Init(int minThread, int maxThread)
{
#if _DEBUG
    _LOG->PrintError("将读取的实体放入预处理列表");
#endif // NDEBUG
    //将实体放入待处理列表，设置时间状态为结束，等待时间线程开启
    ModelManager::GetInstance()->SetAllModelToReadyVec();
    m_canAdvance = ADV_READY;

#if _DEBUG
    _LOG->PrintError("开启时间管理线程");
#endif // NDEBUG
    //开启时间线程
    m_TimeAdvancer_Thread = new thread(TimeAdvanceManager, this);
    m_TimeAdvancer_Thread->detach();

#if _DEBUG
    _LOG->PrintError("初始化线程池，minThread=" + to_string(minThread) + ", maxThread =" + to_string(maxThread));
#endif // NDEBUG
    //初始化线程池
    ErrorState err;
    if (!Init_ThreadPool(minThread, maxThread))
    {
        return THREADPOOLERR;
    }

#if _DEBUG
    _LOG->PrintError("引擎初始化完成");
#endif // NDEBUG
    m_isStart = true;
    return NERROR;
}

bool MyEngine::GetScenarioReadStu()
{
    bool ret;
    m_Mutex.lock();
    ret = m_isScenarioRead;
    m_Mutex.unlock();
    return ret;
}

bool MyEngine::GetStartStu()
{
    bool ret;
    m_Mutex.lock();
    ret = m_isStart;
    m_Mutex.unlock();
    return ret;
}

bool MyEngine::ReadScenario(std::string filename, std::string &errStr)
{
    errStr = "no error";
#if _DEBUG
    _LOG->GetInstance()->PrintError("Read Scenario File: " + filename);
#endif // NDEBUG

    TiXmlDocument* xmlDocument = new TiXmlDocument();
    if (!xmlDocument->LoadFile(filename.c_str())) //没有test.xml文件
    {
        std::string err = xmlDocument->ErrorDesc();
        #if _DEBUG
                _LOG->GetInstance()->PrintError("Read Scenario err: " + err);
        #endif // NDEBUG

        delete xmlDocument;
        return false;
    }
    TiXmlElement* rootElement = xmlDocument->FirstChildElement("scenario");
    if (rootElement == nullptr) //节点不存在
    {
        delete xmlDocument;
        return false;
    }
    if (rootElement)
    {
        TiXmlElement* modelsElement = rootElement->FirstChildElement("Models");
        {
            if (modelsElement)
            {
                TiXmlElement* Element = nullptr;
                for (TiXmlElement* childElement = modelsElement->FirstChildElement();
                    childElement != nullptr; childElement = childElement->NextSiblingElement())
                {
                    std::string str =  childElement->Value();
                    if (str == "Human")
                    {
                        Element = childElement;
                        for (TiXmlElement* unitElement = Element->FirstChildElement("unit");
                            unitElement != nullptr; unitElement = unitElement->NextSiblingElement("unit"))
                        {
                            int id = 0;
                            std::string type;
                            GetTypeFromTiXmlElement(type, unitElement);
                            GetIDFromTiXmlElement(id, unitElement);
                      
                            HINSTANCE hDll;
                            #if _DEBUG
                                std::string dllPath = "dll\\Debug\\" + type + "d.dll";
                                hDll = LoadLibrary(stringToLPCWSTR(dllPath));
                            #endif
                            #if NDEBUG
                                std::string dllPath = "dll\\Release\\" + type + ".dll";
                                hDll = LoadLibrary(stringToLPCWSTR(dllPath));
                            #endif
                            if (hDll == NULL)
                            {
                                std::cout << "Load dll failed!";
                                return -1;
                            }
                            using functionPtr = ModelBase*(*)();
                            functionPtr addFunction = (functionPtr)GetProcAddress(hDll, "CreateModel");
                            if (addFunction == NULL)
                            {
                                std::cout << "cannot find target function!";
                                return -1;
                            }
                            ModelBase* model = addFunction();
                            model->SetServiceInterFace();
                            model->Init(unitElement);
                            model->ReadScenario();
                            model->SetID(id);
                            //初始化组件
                            
                            model->InitComponent();
                            Model_BasicInfo modelInfo;
                            model->GetBasicInfo(modelInfo);
                            _LOG->AddModelToLog(modelInfo);
                            MM->AppendModel(model);
                        }
                    }
                    else if (str == "UAV")
                    {
                        Element = childElement;
                        for (TiXmlElement* unitElement = Element->FirstChildElement("unit");
                            unitElement != nullptr; unitElement = unitElement->NextSiblingElement("unit"))
                        {
                            int id = 0;
                            std::string type;
                            GetTypeFromTiXmlElement(type, unitElement);
                            GetIDFromTiXmlElement(id, unitElement);

                            HINSTANCE hDll;
                            #if _DEBUG
                            std::string dllPath = "dll\\Debug\\" + type + "d.dll";
                            hDll = LoadLibrary(stringToLPCWSTR(dllPath));
                            #endif
                            #if NDEBUG
                            std::string dllPath = "dll\\Release\\" + type + ".dll";
                            hDll = LoadLibrary(stringToLPCWSTR(dllPath));
                            #endif
                            if (hDll == NULL)
                            {
                                std::cout << "Load dll failed!";
                                return -1;
                            }
                            using functionPtr = ModelBase * (*)();
                            functionPtr addFunction = (functionPtr)GetProcAddress(hDll, "CreateModel");
                            if (addFunction == NULL)
                            {
                                std::cout << "cannot find target function!";
                                return -1;
                            }
                            ModelBase* model = addFunction();
                            model->SetServiceInterFace();
                            model->Init(unitElement);
                            model->ReadScenario();
                            model->SetID(id);
                            //初始化组件
                            model->InitComponent();
                            Model_BasicInfo modelInfo;
                            model->GetBasicInfo(modelInfo);
                            _LOG->AddModelToLog(modelInfo);
                            MM->AppendModel(model);
                        }
                    }
                }
            }
        }
    }
    #if _DEBUG
        _LOG->GetInstance()->PrintError("读取想定成功");
    #endif // NDEBUG
    m_Mutex.lock();
    m_isScenarioRead = true;
    m_Mutex.unlock();
    return true;
}

bool MyEngine::Init_ThreadPool(int min, int max)
{
    if (m_pool == nullptr)
    {
        m_pool = new ThreadPool(min,max);
        for (int i = 0; i < max; i++)
        {
            m_pool->Add(ModelRunner, (void*)5);//参数5，暂时没有用，先留着，后面有用的话就不要临时加
        }
    }
    #if _DEBUG
        _LOG->GetInstance()->PrintError("初始化线程池成功");
    #endif // NDEBUG
    return true;
}

void MyEngine::GetThreadNum(int& aliveNum, int& busyNum)
{
    aliveNum = 0;
    busyNum = 0;
    if (m_pool != nullptr)
    {
        aliveNum = m_pool->AliveNum();
        busyNum = m_pool->BusyNum();
    }
}

void MyEngine::SetAdvanceStu(TimeAdvanceStu stu)
{
    m_Mutex.lock();
    m_canAdvance = stu;
    m_Mutex.unlock();
}

void MyEngine::SetLogStu(bool stu)
{
    _LOG->SetLogStu(stu);
}

void MyEngine::BattleTimeAdvance()
{
    m_Mutex.lock();
    m_battleTime += 0.1;
    m_Mutex.unlock();
}

void MyEngine::PutEvent(EventBase* event)
{
    m_Mutex.lock();
    m_eventList.push_back(event);
    m_Mutex.unlock();
}

vector<EventBase*> MyEngine::GetEvents(int id)
{
    vector<EventBase*> ret;
    m_Mutex.lock();
    for (auto iter = m_eventList.begin(); iter != m_eventList.end(); iter++)
    {
        EventBase *event = *iter;
        if (event->receicerID == id || event->receicerID == 0)
        {
            ret.push_back(std::move(event));
            iter = m_eventList.erase(iter);
            if (iter == m_eventList.end())
            {
                break;
            }
        }
    }
    m_Mutex.unlock();
    return ret;
}
                                               
double MyEngine::GetBattleTime()
{
    double t;
    m_Mutex.lock();
    t = m_battleTime;
    m_Mutex.unlock();
    return t;
}

TimeAdvanceStu MyEngine::GetAdvanceStu()
{
    TimeAdvanceStu stu;
    m_Mutex.lock();
    stu = m_canAdvance;
    m_Mutex.unlock();
    return stu;
}

void MyEngine::GetAllModels(std::vector<Model_BasicInfo>& modelsList)
{
    ModelManager::GetInstance()->GetAllModels(modelsList);
}

void MyEngine::GetModelByID(Model_BasicInfo& model,int id)
{
    ModelManager::GetInstance()->GetModelByID(model,id);
}

void MyEngine::OperatService()
{
    if (_serviceInterface)
    {
        ServiceBase* service = _serviceInterface->GetServiceByName("ModelManagerService");
        std::vector<Model_BasicInfo> modelsList;
        MyEngine::GetInstance()->GetAllModels(modelsList);
        service->SetEntityList(modelsList);
    }
}
#include "MyEngine.h"

MyEngine* MyEngine::m_MyEngine = nullptr;
std::mutex MyEngine::m_Mutex;
std::mutex MyEngine::m_Mutex_Advance;

void TestFunction(void* arg)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "ThreadID:" << std::this_thread::get_id() << " :  function....." << std::endl;
    }
}

void TimeAdvanceManager(void* arg)
{
    //在这里设置时间就绪，条件时间状态为处理完成，处理完成设置是模型处理线程处理完模型相关函数后判断待处理的模型为空，并将所有模型放入了处理完毕列表
    //设置时间就绪时，同样要将处理完的模型放进待处理列表
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
    m_pool = nullptr;
    m_isScenarioRead = false;
}

MyEngine::MyEngine(const MyEngine& manager)
{

}

MyEngine::~MyEngine()
{
    //销毁线程池
    if (m_pool)
    {
        delete m_pool;
        m_pool = nullptr;
    }
    //销毁模型管理器
    ModelManager::deleteInstance();
    m_MyEngine = nullptr;
}

ErrorState MyEngine::Init(int minThread, int maxThread)
{
    //将实体放入待处理列表，设置时间状态为就绪

    //初始化线程池
    ErrorState err;
    if (!Init_ThreadPool(minThread, maxThread))
    {
        return THREADPOOLERR;
    }

    return NERROR;
}

bool MyEngine::GetScenarioReadStu()
{
    bool ret;
    m_Mutex.lock();
    ret = m_isScenarioRead;
    m_Mutex.unlock();
    return m_isScenarioRead;
}

bool MyEngine::ReadScenario(std::string filename, std::string &errStr)
{
    errStr = "no error";
    _LOG->GetInstance()->PrintError("Read Scenario File: " + filename);
    TiXmlDocument* xmlDocument = new TiXmlDocument();
    if (!xmlDocument->LoadFile(filename.c_str())) //没有test.xml文件
    {
        std::string err = xmlDocument->ErrorDesc();
        _LOG->PrintError("read XML file: " + err);

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
                TiXmlElement* humanElement = nullptr;
                for (TiXmlElement* childElement = modelsElement->FirstChildElement();
                    childElement != nullptr; childElement = childElement->NextSiblingElement())
                {
                    std::string str =  childElement->Value();
                    if (str == "Human")
                    {
                        humanElement = childElement;
                        for (TiXmlElement* unitElement = humanElement->FirstChildElement("unit");
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
                                hDll = LoadLibrary(L"dll\Debug\People.dll");
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
                            model->Init(unitElement);
                            model->ReadScenario();
                            model->SetID(id);
                            MM->AppendModel(model);
                        }
                    }
                }
            }
        }
    }
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
            m_pool->Add(TestFunction, (void*)5);
        }
    }
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

}

TimeAdvanceStu MyEngine::GetAdvanceStu()
{
    return ADV_FINISH;
}
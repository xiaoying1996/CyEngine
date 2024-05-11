#include "MyEngine.h"

MyEngine* MyEngine::m_MyEngine = nullptr;
std::mutex MyEngine::m_Mutex;

void TestFunction(void* arg)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "ThreadID:" << std::this_thread::get_id() << " :  function....." << std::endl;
    }
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
    m_MyEngine = nullptr;
}

ErrorState MyEngine::Init(int minThread, int maxThread)
{
    //初始化线程池
    ErrorState err;
    if (!Init_ThreadPool(minThread, maxThread))
    {
        return THREADPOOLERR;
    }

    return NERROR;
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
                            for (TiXmlElement* valElement = unitElement->FirstChildElement();
                                valElement != nullptr; valElement = valElement->NextSiblingElement())
                            {
                                std::string key = valElement->Value();
                                if (key == "type")
                                {
                                    int i = 0;
                                }
                                if (key == "id")
                                {
                                    int i = 0;
                                }
                                if (key == "position")
                                {
                                    for (TiXmlElement* posElement = valElement->FirstChildElement();
                                        posElement != nullptr; posElement = posElement->NextSiblingElement())
                                    {
                                        if (key == "lon")
                                        {
                                            int i = 0;
                                        }
                                        if (key == "lat")
                                        {
                                            int i = 0;
                                        }
                                        if (key == "alt")
                                        {
                                            int i = 0;
                                        }
                                    }
                                }
                            }

                           
                        }
                    }
                }
            }
        }
    }
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
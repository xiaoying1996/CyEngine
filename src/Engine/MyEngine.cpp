#include "MyEngine.h"

MyEngine* MyEngine::m_MyEngine = nullptr;
std::mutex MyEngine::m_Mutex;

void TestFunction(void* arg)
{
    for (int i = 0; i < 100; i++)
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
}

ErrorState MyEngine::Init(int minThread, int maxThread)
{
    //初始化线程池
    ErrorState err;
    if (!Init_ThreadPool(minThread, maxThread))
    {
        return THREADPOOLERR;
    }

    return NOERROR;
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
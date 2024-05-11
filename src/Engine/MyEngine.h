#include "../Public/PublicInclude.h"
#include "../Service/LogReport/LogReport.h"
#include "ThreadPool/ThreadPool.h"

class MyEngine {
public:
    ~MyEngine();
    static MyEngine* GetInstance();
    static void deleteInstance();

    ErrorState Init(int minThread,int maxThread);
    bool ReadScenario(std::string filename,std::string &errStr);
    bool Init_ThreadPool(int min,int max);
    void GetThreadNum(int &aliveNum,int &busyNum);
private:
    MyEngine();
    MyEngine(const MyEngine& manager);
    const MyEngine& operator=(const MyEngine& manager);

private:
    static MyEngine* m_MyEngine;
    static std::mutex m_Mutex;
    ThreadPool* m_pool = nullptr;
};
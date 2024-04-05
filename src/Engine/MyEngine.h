#include "../Public/PublicInclude.h"
#include "ThreadPool/ThreadPool.h"

class MyEngine {
public:
    ~MyEngine();
    static MyEngine* GetInstance();
    static void deleteInstance();

    ErrorState Init(int minThread,int maxThread);
    bool Init_ThreadPool(int min,int max);
private:
    MyEngine();
    MyEngine(const MyEngine& manager);
    const MyEngine& operator=(const MyEngine& manager);

private:
    static MyEngine* m_MyEngine;
    static std::mutex m_Mutex;
    ThreadPool* m_pool = nullptr;
};
#include "../Public/PublicInclude.h"
#include "../Service/LogReport/LogReport.h"
#include "ThreadPool/ThreadPool.h"
#include "ModelManager.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>

class MyEngine {
public:
    ~MyEngine();
    static MyEngine* GetInstance();
    static void deleteInstance();

    ErrorState Init(int minThread,int maxThread);
    bool GetScenarioReadStu();
    bool ReadScenario(std::string filename,std::string &errStr);
    bool Init_ThreadPool(int min,int max);
    TimeAdvanceStu GetAdvanceStu();
    void GetThreadNum(int &aliveNum,int &busyNum);
    void SetAdvanceStu(TimeAdvanceStu stu);
    void SetLogStu(bool stu);
    void BattleTimeAdvance();
    double GetBattleTime();

private:
    MyEngine();
    MyEngine(const MyEngine& manager);
    const MyEngine& operator=(const MyEngine& manager);

private:
    static MyEngine* m_MyEngine;
    static std::mutex m_Mutex;
    static std::mutex m_Mutex_Advance;
    ThreadPool* m_pool = nullptr;
    thread* m_TimeAdvancer_Thread = nullptr;
    bool m_isScenarioRead;
    double m_battleTime;
    TimeAdvanceStu m_canAdvance;
};
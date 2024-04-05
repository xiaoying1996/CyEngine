#include "../../Public/PublicInclude.h"

using namespace std::literals::chrono_literals;
using callback = void(*)(void*);

class Task
{
public:
    callback function;
    void* arg;
public:
    Task(callback f, void* arg)
    { 
    function = f; 
    this->arg = arg; 
    }
};

class ThreadPool
{
public:
    ThreadPool(int min,int max);
    void Add(callback f,void* arg);
    void Add(Task task);
    int BusyNum();
    int AliveNum();
    ~ThreadPool();
private:
    std::queue<Task> m_taskQueue;
    std::thread m_managerID;
    std::vector<std::thread> m_threadIDs;
    int m_minNum;
    int m_maxNum;
    int m_busyNum;
    int m_liveNum;
    int m_exitNum;

    std::mutex m_mutex;
    std::condition_variable m_cond;
    bool m_shutDowm;
    static void manager(void* arg);
    static void worker(void* arg);
};

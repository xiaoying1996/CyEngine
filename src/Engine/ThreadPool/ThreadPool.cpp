#include "ThreadPool.h"
const int NUMBER = 2;

ThreadPool::ThreadPool(int min, int max)
{
	do {
		m_minNum = min;
		m_maxNum = max;
		m_busyNum = 0;
		m_liveNum = min;
		m_exitNum = 0;
		m_shutDowm = false;
		m_managerID = std::thread(manager,this);
		m_threadIDs.resize(max);
		for (int i = 0; i < min; ++i)
		{
			m_threadIDs[i] = std::thread(worker,this);
		}
	} while (0);
}

ThreadPool::~ThreadPool()
{
	m_shutDowm = true;
	if (m_managerID.joinable())
	{
		m_managerID.join();
	}
	m_cond.notify_all();
	for (int i = 0; i < m_maxNum; ++i)
	{
		if (m_threadIDs[i].joinable())
		{
			m_threadIDs[i].join();
		}
	}
}

void ThreadPool::Add(callback f, void* arg)
{
	std::unique_lock<std::mutex> locker(m_mutex);
	if (m_shutDowm)
	{
		return;
	}
	m_taskQueue.push(Task(f,arg));
	m_cond.notify_all();
}

void ThreadPool::Add(Task task)
{
	std::unique_lock<std::mutex> locker(m_mutex);
	if (m_shutDowm)
	{
		return;
	}
	m_taskQueue.push(task);
	m_cond.notify_all();
}

int ThreadPool::BusyNum()
{
	m_mutex.lock();
	int busy = m_busyNum;
	m_mutex.unlock();
	return busy;
}

int ThreadPool::AliveNum()
{
	m_mutex.lock();
	int alive = m_liveNum;
	m_mutex.unlock();
	return alive;
}

void ThreadPool::manager(void* arg)
{
	ThreadPool* pool = static_cast<ThreadPool*>(arg);
	while (!pool->m_shutDowm)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::unique_lock<std::mutex> locker(pool->m_mutex);
		int queuesize = pool->m_taskQueue.size();
		int livenum = pool->m_liveNum;
		int busynum = pool->m_busyNum;
		locker.unlock();

		if (queuesize>0&&livenum < pool->m_maxNum)
		{
			locker.lock();
			int count = 0;
			for (int i = 0; i < pool->m_maxNum && count < NUMBER && pool->m_liveNum < pool->m_maxNum; ++i)
			{
				if (pool->m_threadIDs[i].get_id() == std::thread::id())
				{
					std::cout << "Create a new  Thread..." << std::endl;
					pool->m_threadIDs[i] = std::thread(worker,pool);
					count++;
					pool->m_liveNum++;
				}
			}
			locker.unlock();
		}
		if (livenum>busynum && livenum > pool->m_minNum)
		{
			locker.lock();
			if(pool->m_exitNum==0)
				pool->m_exitNum = 1;
			locker.unlock();
			for (int i = 0; i < NUMBER; ++i)
			{
				pool->m_cond.notify_all();
			}
		}
	}
}

void ThreadPool::worker(void* arg)
{
	ThreadPool* pool = static_cast<ThreadPool*>(arg);
	while (true)
	{
		std::unique_lock<std::mutex> locker(pool->m_mutex);
		while(pool->m_taskQueue.empty() && !pool->m_shutDowm)
		{
			pool->m_cond.wait(locker);
			if(pool->m_exitNum>0)
			{
				pool->m_exitNum--;
				if (pool->m_liveNum > pool->m_minNum)
				{
					pool->m_liveNum--;
					std::cout << "ThreadID:" << std::this_thread::get_id() << " exit....." << std::endl;
					locker.unlock();
					return;
				}
			}
		}
		if (pool->m_shutDowm)
		{
			std::cout << "ThreadID:" << std::this_thread::get_id() << " exit....." << std::endl;
			return;
		}

		Task task = pool->m_taskQueue.front();
		pool->m_taskQueue.pop();
		pool->m_busyNum++;
		locker.unlock();

		std::cout << "ThreadID:" << std::this_thread::get_id() << " start working....." << std::endl;
		task.function(task.arg);
		task.arg = nullptr;

		std::cout << "ThreadID:" << std::this_thread::get_id() << " end working....." << std::endl;
		locker.lock();
		pool->m_busyNum--;
		locker.unlock();
	}
}

#include "LogReport.h"
#include <Windows.h>
#include <iostream>

LogReport* LogReport::m_LogReport = nullptr;
std::mutex LogReport::m_Mutex;

LogReport* LogReport::GetInstance()
{
    if (m_LogReport == nullptr)
    {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (m_LogReport == nullptr)
        {
            m_LogReport = new (std::nothrow) LogReport();
        }
    }
    return m_LogReport;
}

void LogReport::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex);
    if (m_LogReport)
    {
        delete m_LogReport;
        m_LogReport = nullptr;
    }
}

LogReport::LogReport()
{
    m_log_Stu = false;

    SYSTEMTIME stUTC;
    GetSystemTime(&stUTC);
    m_logPath = std::to_string(stUTC.wYear) + "-" + std::to_string(stUTC.wMonth) + "-" + std::to_string(stUTC.wDay)
        + "_" + std::to_string(stUTC.wHour) + "_" + std::to_string(stUTC.wMinute) + "_" + std::to_string(stUTC.wSecond);
    string folderPath = "Log\\" + m_logPath;
    string command;
    command = "mkdir " + folderPath;
    system(command.c_str());
    //创建引擎主log
}

LogReport::LogReport(const LogReport& manager)
{

}

LogReport::~LogReport()
{
}

void LogReport::PrintError(ErrorState err)
{
    m_Mutex.lock();
    switch (err)
    {
    case NOERROR:
        break;
    case ELSEERROR: 
    {
        std::cout << "ERR: else error for Test" << std::endl;
        break;
    }
    case THREADPOOLERR:
    {
        std::cout << "ERR: ThreadPool Init failed" << std::endl;
        break;
    }
    default:
        break;
    }
    m_Mutex.unlock();
}

void LogReport::PrintError(std::string errStr)
{
    m_Mutex.lock();
    std::cout << errStr << std::endl;
    m_Mutex.unlock();
}

void LogReport::SetLogStu(bool stu)
{
    m_Mutex.lock();
    m_log_Stu = stu;
    m_Mutex.unlock();
}
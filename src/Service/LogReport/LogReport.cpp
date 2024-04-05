#include "LogReport.h"

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
}

LogReport::LogReport(const LogReport& manager)
{

}

LogReport::~LogReport()
{
}

void LogReport::PrintError(ErrorState err)
{
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
}

void LogReport::PrintError(std::string errStr)
{
    std::cout << errStr << std::endl;
}
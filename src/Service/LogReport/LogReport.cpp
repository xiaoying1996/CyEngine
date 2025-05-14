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
    GetLocalTime(&stUTC);
    m_logPath = std::to_string(stUTC.wYear) + "-" + std::to_string(stUTC.wMonth) + "-" + std::to_string(stUTC.wDay)
        + "_" + std::to_string(stUTC.wHour ) + "_" + std::to_string(stUTC.wMinute) + "_" + std::to_string(stUTC.wSecond);
    string folderPath = "Log\\" + m_logPath;
    string command;
    command = "mkdir " + folderPath;
    system(command.c_str());
    //创建引擎主log
    m_EngineLog.open(folderPath + "\\EngineLog.txt", ios::out);
}

LogReport::LogReport(const LogReport& manager)
{

}

LogReport::~LogReport()
{
    m_EngineLog.close();
    for (int i = 0; i < m_modelLog_Vec.size(); i++)
    {
        m_modelLog_Vec[i]->close();
    }
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
    //std::cout << errStr << std::endl;
    m_EngineLog << errStr << endl;
    m_Mutex.unlock();
}

void LogReport::SetLogStu(bool stu)
{
    m_Mutex.lock();
    m_log_Stu = stu;
    m_Mutex.unlock();
}

void LogReport::AddModelToLog(Model_BasicInfo modelInfo)
{
    m_Mutex.lock();
    if (m_modelLog_Map.find(modelInfo._id) == m_modelLog_Map.end())
    {
        std::ofstream *logoutFile = new ofstream;
        m_modelLog_Vec.push_back(logoutFile);
        m_modelLog_Map[modelInfo._id] = m_modelLog_Vec.size()-1;
        logoutFile->open("Log\\" +  m_logPath + "\\" + modelInfo._name + ".txt", ios::out);
        *logoutFile << "ID:" + to_string(modelInfo._id) << endl;
        *logoutFile << "Name:" + string(modelInfo._name) << endl;
        string typeStr;
        switch (modelInfo._type)
        {
            case 0:
            {
                typeStr = "UNKnow";
                break;
            }
            case 1:
            {
                typeStr = "People";
                break;
            }
            default:
            {
                typeStr = "Else";
                break;
            }
        }
        *logoutFile << "Type:" + typeStr << endl;
        *logoutFile << "Position:" + to_string(modelInfo._pos._lon)  + "," + to_string(modelInfo._pos._lat) + "," + to_string(modelInfo._pos._alt) << endl;
        *logoutFile << "Shape:" + to_string(modelInfo._shape._length) + "," + to_string(modelInfo._shape._width) + "," + to_string(modelInfo._shape._hight) << endl;
    }
    
    m_Mutex.unlock();
}
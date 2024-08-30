#ifndef _LOGREPORT_
#define _LOGREPORT_

#include "../../Public/PublicInclude.h"
#include <fstream>

#define _LOG LogReport::GetInstance()

class LogReport {
public:
    static LogReport* GetInstance();
    static void deleteInstance();

    void PrintError(ErrorState err);
    void PrintError(std::string errStr);
    void SetLogStu(bool stu);
    void AddModelToLog(Model_BasicInfo modelInfo);

private:
    LogReport();
    ~LogReport();

    LogReport(const LogReport& manager);
    const LogReport& operator=(const LogReport& manager);

private:
    static LogReport* m_LogReport;
    static std::mutex m_Mutex;
    std::string m_logPath;
    ofstream m_EngineLog;
    bool m_log_Stu;//lon״̬��Ĭ�Ϲر�
    std::map<int, int> m_modelLog_Map;//ģ�������Ӧ��log�ļ���
    std::vector<ofstream*> m_modelLog_Vec;

};

#endif // !_LOGREPORT_
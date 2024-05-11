#ifndef _LOGREPORT_
#define _LOGREPORT_

#include "../../Public/PublicInclude.h"

#define _LOG LogReport::GetInstance()

class LogReport {
public:
    static LogReport* GetInstance();
    static void deleteInstance();

    void PrintError(ErrorState err);
    void PrintError(std::string errStr);

private:
    LogReport();
    ~LogReport();

    LogReport(const LogReport& manager);
    const LogReport& operator=(const LogReport& manager);

private:
    static LogReport* m_LogReport;
    static std::mutex m_Mutex;
};

#endif // !_LOGREPORT_
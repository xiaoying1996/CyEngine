#ifndef _WRITEREADSHAREMEMORY_
#define _WRITEREADSHAREMEMORY_
#include "Windows.h"
#include "Public/PublicStruct.h"
#include <string>

void CreateSmData(SMStruct sm,string shareMemoryID, HANDLE &hMapFile, SMStruct* &pData);
SMStruct GetSMData(HANDLE hMapFile, SMStruct* pData);
void SetSMData(SMStruct sm, SMStruct* pData);

#endif // !_WRITEREADSHAREMEMORY_

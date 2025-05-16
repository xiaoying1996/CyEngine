#include "WriteReadShareMemory.h"

void CreateSmData(SMStruct sm,string shareMemoryID, HANDLE& hMapFile, SMStruct* &pData)
{
	std::wstring wideStr(shareMemoryID.begin(), shareMemoryID.end());
	LPCWSTR lpcwstr = wideStr.c_str();
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // 使用分页文件
		NULL,                    // 默认安全属性
		PAGE_READWRITE,          // 读写权限
		0,                       // 高序DWORD的文件映射大小
		sizeof(SMStruct),      // 低序DWORD的文件映射大小
		lpcwstr); // 共享内存名称

	if (hMapFile == NULL) {
		std::cerr << "CreateFileMapping failed: " << GetLastError() << std::endl;//***错误后面写道log服务里
		return;
	}

	pData = (SMStruct*)MapViewOfFile(
		hMapFile,                // 映射对象句柄
		FILE_MAP_ALL_ACCESS,     // 读写权限
		0,
		0,
		sizeof(SMStruct));

	if (pData == NULL) {
		std::cerr << "MapViewOfFile failed: " << GetLastError() << std::endl;//***错误后面写道log服务里
		CloseHandle(hMapFile);
		return;
	}
	pData->basicInfo = sm.basicInfo;
	pData->otherInfo = sm.otherInfo;
}

SMStruct GetSMData(HANDLE hMapFile, SMStruct* pData)
{
	SMStruct sm;
	if (hMapFile && pData)
	{
		sm.basicInfo = pData->basicInfo;
		sm.otherInfo = pData->otherInfo;
	}
	return sm;
}

void SetSMData(SMStruct sm, SMStruct* pData)
{
	*pData = sm;
}
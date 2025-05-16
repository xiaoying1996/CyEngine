#include "WriteReadShareMemory.h"

void CreateSmData(SMStruct sm,string shareMemoryID, HANDLE& hMapFile, SMStruct* &pData)
{
	std::wstring wideStr(shareMemoryID.begin(), shareMemoryID.end());
	LPCWSTR lpcwstr = wideStr.c_str();
	hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // ʹ�÷�ҳ�ļ�
		NULL,                    // Ĭ�ϰ�ȫ����
		PAGE_READWRITE,          // ��дȨ��
		0,                       // ����DWORD���ļ�ӳ���С
		sizeof(SMStruct),      // ����DWORD���ļ�ӳ���С
		lpcwstr); // �����ڴ�����

	if (hMapFile == NULL) {
		std::cerr << "CreateFileMapping failed: " << GetLastError() << std::endl;//***�������д��log������
		return;
	}

	pData = (SMStruct*)MapViewOfFile(
		hMapFile,                // ӳ�������
		FILE_MAP_ALL_ACCESS,     // ��дȨ��
		0,
		0,
		sizeof(SMStruct));

	if (pData == NULL) {
		std::cerr << "MapViewOfFile failed: " << GetLastError() << std::endl;//***�������д��log������
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
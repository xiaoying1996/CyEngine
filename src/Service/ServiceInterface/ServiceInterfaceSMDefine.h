#ifndef _SERVIICEINTERFACESMDEFINE_
#define _SERVIICEINTERFACESMDEFINE_

#include <windows.h>
#include <iostream>

struct ShareMemoryData {
	LPCWSTR shareMemoryName;
	int bufferSize;
};

//std::string s = 

ShareMemoryData GetServiceInterfaceSMData()
{
	ShareMemoryData data;
	data.shareMemoryName = L"ServiceInterSM";
	data.bufferSize = 128;
	return data;
}

#endif // !_SERVIICEINTERFACESMDEFINE_


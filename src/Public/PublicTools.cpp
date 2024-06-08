#include "PublicTools.h"

LPCWSTR stringToLPCWSTR(string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t* wcstring = new wchar_t[sizeof(wchar_t) * (orig.length() - 1)];
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
	return wcstring;
}

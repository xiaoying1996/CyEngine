#include "Engine/MyEngine.h"
#include "Service/LogReport/LogReport.h"

int main()
{
	MyEngine* myEngine = MyEngine::GetInstance();
	ErrorState err = myEngine->Init(1,10);
	
	if (err != 1)
	{
		_LOG->PrintError(err);
	}
	else {
		_LOG->PrintError("Engine Init Successed");
	}
	while (1);
}
#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include "PublicStruct.h"

class ModelBase {
public:
	ModelBase();
	virtual ~ModelBase();
	virtual void Init();
	virtual void ReadScenario();
	virtual void Run();
	virtual void PostEvent();
	virtual void ReceiveEvent();
	virtual void Destory();

private:
	Model_Position _pos;
	Model_Shape _shape;
};

#endif // !_MODEL_BASE_

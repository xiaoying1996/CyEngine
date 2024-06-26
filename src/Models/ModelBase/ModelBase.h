#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include "PublicStruct.h"
#include "../../Public/PublicEnum.h"

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

	void SetID(int id);

private:
	int id;
	ModelType type;
	Model_Position _pos;
	Model_Shape _shape;
};

#endif // !_MODEL_BASE_

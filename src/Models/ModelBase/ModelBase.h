#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include "PublicStruct.h"
#include "../../Public/PublicInclude.h"
#include "../../Public/PublicEnum.h"
#include "Tools/XML_Utils/XML_Utils.h"

class ModelBase {
public:
	ModelBase();
	virtual ~ModelBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void Run();
	virtual void PostEvent();
	virtual void ReceiveEvent();
	virtual void Destory();

	void SetID(int id);
	void GetBasicInfo(Model_BasicInfo &info);

private:
	bool _isInit;
	bool _isReadScenario;
	int _id;
	Model_Position _pos;
	Model_Shape _shape;
	string _name;

protected:
	ModelType _type;
};

#endif // !_MODEL_BASE_

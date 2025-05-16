#ifndef _SERVICE_BASE_
#define _SERVICE_BASE_
#include "../../Public/PublicEnum.h"
#include "Public/EventStruct.h"
#include "Tools/XML_Utils/XML_Utils.h"
#include "ServiceEnum.h"

class ServiceBase {
public:
	ServiceBase();
	virtual ~ServiceBase();
	virtual void Init(TiXmlElement* unitElement);
	virtual void ReadScenario();
	virtual void PostEvent(EventBase* event);
	virtual void ReceiveEvent(EventBase *event);
	virtual void Run(double t);
	virtual void Destory();
	virtual void PublishRegister();
	void HandleEvent();
	void AddEventPublic(std::vector<EventCategory> events);
	void AddEventRegister(std::vector<EventCategory> events);
	void AddModelPublic(std::vector<ModelType> models);
	void AddModelRegister(std::vector<ModelType> models);
	void GetDataPublicRegister(std::vector<EventCategory> &EventPublic, std::vector<EventCategory> &EventRegister, std::vector<ModelType> &ModelPublic, std::vector<ModelType> &ModelRegister);
	//实体管理服务使用的，后面放到中间类里面去
	void GetAllEventByID(std::vector<Message_Attack>& events,int id);
	//战斗裁决服务使用的，后面放到中间类里面去
	virtual void AddAttackEvent(AttackBase* attack);

protected:
	std::vector<EventCategory> _EventPublic;
	std::vector<EventCategory> _EventRegister;
	std::vector<ModelType> _ModelPublic;
	std::vector<ModelType> _ModelRegister;
	
public:
	ServiceType _type;
	std::vector<AttackResult> _attackResultList;
	std::vector<Message_Attack> _EventListToSend;
};

#endif // !_MODEL_BASE_

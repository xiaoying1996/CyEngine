#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include <Components/ComponentBase/ComponentBase.h>
#include"Service/ServiceInterface/ServiceInterface.h"
#include"Service/ServiceBase/ServiceBase.h"
#include"Service/ModelManagerBaseService/ModelManagerBaseService.h"
#include "DecisionAlgo/DecisionBaseAlgo/DecisionBaseAlgo.h"
using namespace std;
class ModelBase {
public:
	ModelBase();
	virtual ~ModelBase();

	//-----���º������⿪��------
	/*
	* ��ӱ 2025.05.15
	* ͨ��XML�ڵ��ģ�ͽ��г�ʼ��
	* �ⲿ�ӿ�
	* ע����ѭXML�ڵ��еĸ�ʽ
	*/
	virtual void Init(TiXmlElement* unitElement);
	/*
	* * ��ӱ 2025.05.15
	* ͨ���������ݽṹ���ģ�ͽ��г�ʼ��
	* �ⲿ�ӿ�ͬ�����Init������ѡ�����
	* �������Init����ֻ�����һ������
	*/
	virtual void InitByBasicInfo(Model_BasicInfo basicInfo, int jobType, string authname, std::vector<int> subordinates);
	/*
	* * ��ӱ 2025.05.20
	* ����ǰ��׼������
	* ������ģ��Init�����Ժ�������
	* �ɰ�������д
	*/
	virtual void Prepare();
	/*
	* * ��ӱ 2025.05.15
	* ͨ���붨�ļ�������������Դ��ȡ�������
	* ��ѡ���Ե���
	* �ɰ�������д
	*/
	virtual void ReadScenario();
	/*
	* * ��ӱ 2025.05.15
	* ģ�͵�����ִ�к���
	* ÿ������ִ��һ��
	* �ɰ�������д
	*/
	virtual void Run(double t);
	/*
	* * * ��ӱ 2025.05.15
	* ��ģ���л�ȡģ�͵�ǰ�Ļ�����Ϣ
	* ����ӿ�
	* ��ǰֻ�Ի������ݽ��д���
	*/
	void GetBasicInfo(Model_BasicInfo &info);
	/*
	* * * ��ӱ 2025.05.15
	* ��ģ���ڲ������¼�
	* ����ӿ�
	*/
	void AddEvent(shared_ptr<EventBase> event);
	/*
	* * * ��ӱ 2025.05.15
	* ��ģ���л�ȡģ�͵�ǰ�������¼�
	* ����ӿ�
	* �¼�����ָ���������ָ�뷽ʽ�洢������Ҫ�ⲿ�ֶ�����
	*/
	vector<shared_ptr<EventBase>> HandleEvent();

	//-----���º����Ƕ��⿪��------
	/*
	* * ��ӱ 2025.05.15
	* ģ������
	*/
	virtual void Destory();
	/*
	* ��ӱ 2025.05.15
	* �����¼����¼��������
	* δ���ƣ�����δ����
	*/
	virtual void PostEvent();
	/*
	* ��ӱ 2025.05.15
	* ģ�ͽ����¼�
	* �ú������¼�����������
	* δ����
	*/
	virtual void ReceiveEvent(shared_ptr<EventBase> event);
	/*
	* ��ӱ 2025.05.19
	* ���¼�ת������ע��͹����¼�����
	*/
	virtual void RegisterPublishEvent();

	//����Ϊģ���ڲ�ʹ�ýӿڣ������⿪��
protected:
	void InitComponent();
	void SetServiceInterFace();
	double GetHealth();
	void SetHealth(double health);
	void SetType(int type);
	Model_Position GetPos();
	int GetType();
	int GetID();
	void SetHurt(double hurt);
	void SetModelFunction(vector<ModelFunction> f);
	vector<ModelFunction> GettModelFunction();
	ServiceInterface* _serviceInter = nullptr;
	ModelManagerBaseService* _modelManagerService = nullptr;
private:
	std::vector<ComponentBase*> _myComponents;
	bool _isInit;
	bool _isReadScenario;
	int _id;
	int _type;
	vector<ModelFunction> _modelFun;//ģ�Ϳ�ִ�й���
	string _shareMemoryID;
	vector<shared_ptr<EventBase>> _eventsToSend;
	SMStruct* pData;
	HANDLE hMapFile;

public:
	JobType _job;
	vector<int> _subordinates;
	string _authName;
	vector<FormationStu> _subordinateStus;
};

#endif // !_MODEL_BASE_

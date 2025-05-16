#ifndef _MODEL_BASE_
#define _MODEL_BASE_
#include <Components/ComponentBase/ComponentBase.h>
#include"Service/ServiceInterface/ServiceInterface.h"
#include"Service/ServiceBase/ServiceBase.h"
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
	virtual void InitByBasicInfo(Model_BasicInfo basicInfo);
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
	* * ��ӱ 2025.05.15
	* ģ������
	*/
	virtual void Destory();
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
	*ע��:�м�ִ����ú���֮��Ҫ�Բ�������������٣�һ������¿����߲�����ģ���ڲ����ⲿ���ݽ�������,�����̲�ס
	*/
	void AddEvent(EventBase* event);
	/*
	* * * ��ӱ 2025.05.15
	* ��ģ���л�ȡģ�͵�ǰ�������¼�
	* ����ӿ�
	* �¼�����ָ���������ָ�뷽ʽ�洢������Ҫ�ⲿ�ֶ�����
	*/
	vector<EventBase*> HandleEvent();

	//-----���º����Ƕ��⿪��------
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
	virtual void ReceiveEvent(EventBase* event);

	//����Ϊģ���ڲ�ʹ�ýӿڣ������⿪��
protected:
	void InitComponent();
	void SetServiceInterFace();
	double GetHealth();
	void SetHealth(double health);
	void SetType(int type);
	Model_Position GetPos();
	int GetType();
	void SetHurt(double hurt);
	ServiceInterface* _serviceInter = nullptr;
private:
	std::vector<ComponentBase*> _myComponents;
	bool _isInit;
	bool _isReadScenario;
	int _id;
	int _type;
	string _shareMemoryID;
	vector<EventBase*> _eventsToSend;
	SMStruct* pData;
	HANDLE hMapFile;
};

#endif // !_MODEL_BASE_

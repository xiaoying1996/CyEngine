#ifndef _MODEL_MANAGER
#define _MODEL_MANAGER

/*
* ModelManager����������ģ��ʵ�����й���
* 1 ����ȡ�붨���붨�е�ʵ�����ģ�������б�
* 2 ������ʱ������ʵ��
* 3 ����Ϸ�����ж���������ģ�͡�Ԥ������ģ�͡��������ģ�ͽ��й���
*/

#include "Models/ModelBase/ModelBase.h"
#include <list>
#include <vector>
#include <mutex>
#include "../Service/LogReport/LogReport.h"

#define MM ModelManager::GetInstance()

class ModelManager
{
public:
	~ModelManager();
	static ModelManager* GetInstance();
	static void deleteInstance();

	void AppendModel(ModelBase* model);
	void SetAllModelToReadyVec();
	void AddModelToRunningVec(ModelBase* model);
	void MoveModelFromRunningToFinish(ModelBase* model);
	void MoveAllModelsFromFinishToReady();
	bool Is_model_Finish_Vec_Empty();
	bool Is_model_Running_Vec_Empty();
	void GetAllModels(std::vector<Model_BasicInfo> &models);
	void GetModelByID(Model_BasicInfo & model,int id);

	ModelBase* GetModelForRunn();
private:
	ModelManager();
	ModelManager(const ModelManager& manager);
	const ModelManager& operator=(const ModelManager& manager);

private:
	static ModelManager* m_ModelManager;
	static mutex m_Mutex;
	static mutex m_Mutex_Model;
	static mutex m_Mutex_ModelReadyRun;
	static mutex m_Mutex_ModelRunning;
	static mutex m_Mutex_ModelFinish;
	vector<ModelBase*> m_model_Vec;	//��ǰ�����д��ڵ�����ʵ��
	vector<ModelBase*> m_model_ReadyRun_Vec;//��ǰ������׼��ִ�е�ʵ��
	vector<ModelBase*> m_model_Running_Vec;//��ǰ����������ִ�е�ʵ��
	vector<ModelBase*> m_model_Finish_Vec;//��ǰ���������ִ�е�ʵ��
};

#endif // !_MODEL_MANAGER

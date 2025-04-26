#ifndef _MODEL_MANAGER
#define _MODEL_MANAGER

/*
* ModelManager对象用来对模型实例进行管理
* 1 将读取想定将想定中的实体加入模型运行列表
* 2 加入临时创建的实体
* 3 在游戏过程中对正在运行模型、预备运行模型、运行完毕模型进行管理
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
	vector<ModelBase*> m_model_Vec;	//当前环境中存在的所有实体
	vector<ModelBase*> m_model_ReadyRun_Vec;//当前环境中准备执行的实体
	vector<ModelBase*> m_model_Running_Vec;//当前环境中正在执行的实体
	vector<ModelBase*> m_model_Finish_Vec;//当前环境中完成执行的实体
};

#endif // !_MODEL_MANAGER

#include "ModelManager.h"

ModelManager* ModelManager::m_ModelManager = nullptr;
std::mutex ModelManager::m_Mutex;
std::mutex ModelManager::m_Mutex_Model;
std::mutex ModelManager::m_Mutex_ModelReadyRun;
std::mutex ModelManager::m_Mutex_ModelRunning;
std::mutex ModelManager::m_Mutex_ModelFinish;

ModelManager::ModelManager()
{
}

ModelManager* ModelManager::GetInstance()
{
    if (m_ModelManager == nullptr)
    {
        std::unique_lock<std::mutex> lock(m_Mutex);
        if (m_ModelManager == nullptr)
        {
            m_ModelManager = new (std::nothrow) ModelManager();
        }
    }
    return m_ModelManager;
}

void ModelManager::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex);
    if (m_ModelManager)
    {
        delete m_ModelManager;
        m_ModelManager = nullptr;
    }
}

ModelManager::~ModelManager()
{
	vector<ModelBase*> vtTemp;
	m_model_Vec.swap(vtTemp);
}

void ModelManager::AppendModel(ModelBase* model)
{
    m_Mutex_Model.lock();
	m_model_Vec.push_back(model);
    m_Mutex_Model.unlock();
}

void ModelManager::AddModelToRunningVec(ModelBase* model)
{
    m_Mutex_ModelRunning.lock();
    m_model_Running_Vec.push_back(model);
    m_Mutex_ModelRunning.unlock();
}

void ModelManager::MoveModelFromRunningToFinish(ModelBase* model)
{
    m_Mutex_ModelRunning.lock();
    for (auto iter = m_model_Running_Vec.begin(); iter != m_model_Running_Vec.end(); iter++)
    {
        if (model == *iter)
        {
            m_model_Running_Vec.erase(iter);
            break;
        }
    }
    m_Mutex_ModelRunning.unlock();
    m_Mutex_ModelFinish.lock();
    m_model_Finish_Vec.push_back(model);
    m_Mutex_ModelFinish.unlock();
   
}

void ModelManager::MoveAllModelsFromFinishToReady()
{
    m_Mutex.lock();
    if (m_model_ReadyRun_Vec.size())
    {
        _LOG->PrintError("模型管理器: 预处理列表还存在模型，无法重置Ready");
    }
    if (m_model_Running_Vec.size())
    {
        _LOG->PrintError("模型管理器: 正在处理列表还存在模型，无法重置Ready");
    }
    if (m_model_Finish_Vec.size())
    {
        m_model_ReadyRun_Vec = m_model_Finish_Vec;
        m_model_Finish_Vec.clear();
    }
    m_Mutex.unlock();
}

void ModelManager::SetAllModelToReadyVec()
{
    m_Mutex_ModelReadyRun.lock();
    m_model_ReadyRun_Vec.clear();
    m_model_ReadyRun_Vec = m_model_Vec;
    m_Mutex_ModelReadyRun.unlock();
    _LOG->PrintError("已将环境中所有模型置于就绪态");
}

ModelBase* ModelManager::GetModelForRunn()
{
    ModelBase* model = nullptr;
    m_Mutex_ModelReadyRun.lock();
    if (m_model_ReadyRun_Vec.size())
    {
        model = m_model_ReadyRun_Vec[0];
        m_model_ReadyRun_Vec.erase(m_model_ReadyRun_Vec.begin());
    }
    m_Mutex_ModelReadyRun.unlock();
    return model;
}

bool ModelManager::Is_model_Finish_Vec_Empty()
{
    bool b;
    m_Mutex_ModelFinish.lock();
    b = m_model_Finish_Vec.empty();
    m_Mutex_ModelFinish.unlock();
    return b;
}

bool ModelManager::Is_model_Running_Vec_Empty()
{
    bool b;
    m_Mutex_ModelRunning.lock();
    b = m_model_Running_Vec.empty();
    m_Mutex_ModelRunning.unlock();
    return b;
}

void ModelManager::GetAllModels(std::vector<Model_BasicInfo>& models)
{
    m_Mutex_Model.lock();
    for (int i = 0;i<m_model_Vec.size();i++)
    {
        Model_BasicInfo info;
        m_model_Vec[i]->GetBasicInfo(info);
        models.push_back(info);
    }
    m_Mutex_Model.unlock();
}

void ModelManager::GetAllModels(std::vector<ModelBase*>& models)
{
    m_Mutex_Model.lock();
    for (int i = 0; i < m_model_Vec.size(); i++)
    {
        models.push_back(m_model_Vec[i]);
    }
    m_Mutex_Model.unlock();
}

void ModelManager::GetModelByID(Model_BasicInfo& model, int id)
{
    m_Mutex_Model.lock();
    for (int i = 0; i < m_model_Vec.size(); i++)
    {
        Model_BasicInfo info;
        m_model_Vec[i]->GetBasicInfo(info);
        if (info._id == id)
        {
            model = info;
        }
    }
    m_Mutex_Model.unlock();
}
#include "ModelManager.h"

ModelManager* ModelManager::m_ModelManager = nullptr;
std::mutex ModelManager::m_Mutex;

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
	m_Mutex.lock();
	m_model_Vec.push_back(model);
	m_Mutex.unlock();
}

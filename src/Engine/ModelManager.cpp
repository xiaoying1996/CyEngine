#include "ModelManager.h"

ModelManager* ModelManager::m_ModelManager = nullptr;

ModelManager::ModelManager()
{
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

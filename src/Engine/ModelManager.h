#ifndef _MODEL_MANAGER
#define _MODEL_MANAGER

#include <list>
#include <vector>
#include "../Public/PublicInclude.h"

class ModelManager
{
public:
	~ModelManager();
	static ModelManager* GetInstance();
	static void deleteInstance();

	void AppendModel(ModelBase* model);
private:
	ModelManager();
	ModelManager(const ModelManager& manager);
	const ModelManager& operator=(const ModelManager& manager);

private:
	static ModelManager* m_ModelManager;
	static mutex m_Mutex;
	static mutex m_Data_Mutex;
	vector<ModelBase*> m_model_Vec;
};

#endif // !_MODEL_MANAGER

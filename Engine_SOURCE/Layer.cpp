#include "Layer.h"
#include "GameObject.h"

namespace Game
{
	Layer::Layer()
		: Entity("Layer")
	{
	}
	Layer::~Layer()
	{
		Utility::DeleteMap<std::string, GameObject*>(m_MapGameObjects);
	}

	void Layer::AddGameObject(GameObject* const object)
	{
		const std::string& objectName = object->GetName();
		auto iter = m_MapGameObjects.find(objectName);
		if (iter != m_MapGameObjects.end())
			assert(0);
		m_MapGameObjects.insert(std::make_pair(objectName, object));
	}
	void Layer::DeleteGameObject(const std::string& objectName)
	{
		auto iter = m_MapGameObjects.find(objectName);
		if (iter == m_MapGameObjects.end())
			assert(0);
		m_MapGameObjects.erase(objectName);
	}
	void Layer::Update(float dt)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->Update(dt);
	}
	void Layer::PostUpdate(float dt, Camera* const curCamera)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->PostUpdate(dt, curCamera);
	}
	void Layer::Render(HDC dc)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->Render(dc);
	}
}


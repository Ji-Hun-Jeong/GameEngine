#include "Scene.h"

namespace Game
{
	Scene::Scene(const std::string& name)
		: Entity(name)
	{}
	Scene::~Scene()
	{
		Utility::DeleteMap<std::string, GameObject*>(m_MapGameObjects);
	}

	void Scene::Update(float dt)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->Update(dt);
	}

	void Scene::PostUpdate(float dt)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->PostUpdate(dt);
	}

	void Scene::Render(HDC dc)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->Render(dc);
	}

	void Scene::AddGameObject(GameObject* const object)
	{
		const std::string& objectName = object->GetName();
		auto iter = m_MapGameObjects.find(objectName);
		if (iter != m_MapGameObjects.end())
			assert(0);
		m_MapGameObjects.insert(std::make_pair(objectName, object));
	}

	void Scene::DeleteGameObject(const std::string& objectName)
	{
		auto iter = m_MapGameObjects.find(objectName);
		if (iter == m_MapGameObjects.end())
			assert(0);
		m_MapGameObjects.erase(objectName);
	}
}
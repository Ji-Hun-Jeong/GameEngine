#include "Scene.h"
#include "Application.h"
extern Game::Application* g_MyApp;
namespace Game
{
	Scene::Scene(const std::string& name, UINT width, UINT height)
		: Entity(name)
		, m_BitmapSet(width, height)
	{

	}
	Scene::~Scene()
	{
		Utility::DeleteMap<std::string, GameObject*>(m_MapGameObjects);
	}

	void Scene::Update(float dt)
	{
		DetectSceneEvent();
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
			iter->second->Render(m_BitmapSet.GetDc());

		BitBlt(dc, 0, 0
			, m_BitmapSet.GetWidth()
			, m_BitmapSet.GetHeight()
			, m_BitmapSet.GetDc(), 0, 0, SRCCOPY);

		Rectangle(m_BitmapSet.GetDc(), 0, 0
			, m_BitmapSet.GetWidth()
			, m_BitmapSet.GetWidth());
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
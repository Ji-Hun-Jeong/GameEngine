#include "Scene.h"
#include "Application.h"
#include "TimeMgr.h"
#include "Camera.h"
extern Game::Application* g_MyApp;
namespace Game
{
	Scene::Scene(const std::string& name, UINT width, UINT height)
		: Entity(name)
		, m_BitmapSet(width, height)
		, m_CurCamera(nullptr)
	{
		m_VecCameras.reserve(10);
	}
	Scene::~Scene()
	{
		Utility::DeleteMap<std::string, GameObject*>(m_MapGameObjects);
		Utility::DeleteVector<Camera*>(m_VecCameras);
	}

	void Scene::Update(float dt)
	{
		DetectSceneEvent();
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->Update(dt);
		for (size_t i = 0; i < m_VecCameras.size(); ++i)
			m_VecCameras[i]->Update(dt);
	}

	void Scene::PostUpdate(float dt)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->PostUpdate(dt, m_CurCamera);
	}

	void Scene::Render(HDC dc)
	{
		for (auto iter = m_MapGameObjects.begin(); iter != m_MapGameObjects.end(); ++iter)
			iter->second->Render(m_BitmapSet.GetDc());
		TimeMgr::GetInst().Render(m_BitmapSet.GetDc());

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

	void Scene::AddCamera(Camera* const camera)
	{
		for (size_t i = 0; i < m_VecCameras.size(); ++i)
		{
			if (m_VecCameras[i]->GetName() == camera->GetName())
				assert(0);
		}
		m_VecCameras.push_back(camera);
	}

	void Scene::DeleteGameObject(const std::string& objectName)
	{
		auto iter = m_MapGameObjects.find(objectName);
		if (iter == m_MapGameObjects.end())
			assert(0);
		m_MapGameObjects.erase(objectName);
	}

	void Scene::SetCurCamera(const std::string& cameraName)
	{
		Camera* foundCamera = nullptr;
		for (size_t i = 0; i < m_VecCameras.size(); ++i)
		{
			if (m_VecCameras[i]->GetName() == cameraName)
			{
				foundCamera = m_VecCameras[i];
				break;
			}
		}
		assert(foundCamera);
		m_CurCamera = foundCamera;
	}
}
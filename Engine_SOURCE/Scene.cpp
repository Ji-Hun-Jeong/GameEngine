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
		Utility::DeleteVector<Camera*>(m_VecCameras);
	}

	void Scene::Update(float dt)
	{
		DetectSceneEvent();
		for (size_t i = 0; i < m_VecCameras.size(); ++i)
			m_VecCameras[i]->Update(dt);
		for (size_t i = 0; i < m_ArrLayers.size(); ++i)
			m_ArrLayers[i].Update(dt);
	}

	void Scene::PostUpdate(float dt)
	{
		for (size_t i = 0; i < m_VecCameras.size(); ++i)
			m_VecCameras[i]->PostUpdate(dt, m_CurCamera);

		for (size_t i = 0; i < m_ArrLayers.size(); ++i)
			m_ArrLayers[i].PostUpdate(dt, m_CurCamera);
		
	}

	void Scene::Render(HDC dc)
	{
		for (size_t i = 0; i < m_ArrLayers.size(); ++i)
			m_ArrLayers[i].Render(m_BitmapSet.GetDc());

		TimeMgr::GetInst().Render(m_BitmapSet.GetDc());

		BitBlt(dc, 0, 0
			, m_BitmapSet.GetWidth()
			, m_BitmapSet.GetHeight()
			, m_BitmapSet.GetDc(), 0, 0, SRCCOPY);

		Rectangle(m_BitmapSet.GetDc(), 0, 0
			, m_BitmapSet.GetWidth()
			, m_BitmapSet.GetWidth());
	}

	void Scene::AddGameObject(eLayerType layerType, GameObject* const object)
	{
		m_ArrLayers[(size_t)layerType].AddGameObject(object);
	}

	void Scene::DeleteGameObject(eLayerType layerType, const std::string& objectName)
	{
		m_ArrLayers[(size_t)layerType].DeleteGameObject(objectName);
	}

	void Scene::AddCamera(Camera* const camera)
	{
		assert(camera);
		for (size_t i = 0; i < m_VecCameras.size(); ++i)
		{
			if (m_VecCameras[i]->GetName() == camera->GetName())
				assert(0);
		}
		m_VecCameras.push_back(camera);
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
	void Scene::SetCurCamera(Camera* const camera)
	{
		assert(camera);
		m_CurCamera = camera;
	}
}
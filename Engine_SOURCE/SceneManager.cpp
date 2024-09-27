#include "SceneManager.h"
#include "TestScene.h"

namespace Game
{
	SceneManager::SceneManager()
		: m_CurScene(nullptr)
	{}
	SceneManager::~SceneManager()
	{
		Utility::DeleteMap<std::string, Scene*>(m_MapScenes);
	}
	void SceneManager::Initalize()
	{
		Scene* scene = new TestScene;
		AddScene(scene);
		m_CurScene = scene;
	}
	void SceneManager::Update()
	{
		m_CurScene->Update();
	}
	void SceneManager::PostUpdate()
	{
		m_CurScene->PostUpdate();
	}
	void SceneManager::Render(HDC dc)
	{
		m_CurScene->Render(dc);
	}
	void SceneManager::AddScene(Scene* const scene)
	{
		const std::string& sceneName = scene->GetName();
		auto iter = m_MapScenes.find(sceneName);
		if (iter != m_MapScenes.end())
			assert(0);
		m_MapScenes.insert(std::make_pair(sceneName, scene));
	}
}
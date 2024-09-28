#include "SceneMgr.h"
#include "TestScene.h"

namespace Game
{
	SceneMgr::SceneMgr()
		: m_CurScene(nullptr)
	{}
	SceneMgr::~SceneMgr()
	{
		Utility::DeleteMap<std::string, Scene*>(m_MapScenes);
	}
	void SceneMgr::Initalize()
	{
		Scene* scene = new TestScene;
		AddScene(scene);
		m_CurScene = scene;
	}
	void SceneMgr::Update()
	{
		m_CurScene->Update();
	}
	void SceneMgr::PostUpdate()
	{
		m_CurScene->PostUpdate();
	}
	void SceneMgr::Render(HDC dc)
	{
		m_CurScene->Render(dc);
	}
	void SceneMgr::AddScene(Scene* const scene)
	{
		const std::string& sceneName = scene->GetName();
		auto iter = m_MapScenes.find(sceneName);
		if (iter != m_MapScenes.end())
			assert(0);
		m_MapScenes.insert(std::make_pair(sceneName, scene));
	}
}
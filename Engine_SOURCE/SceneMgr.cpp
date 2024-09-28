#include "SceneMgr.h"
#include "TestScene.h"
#include "TimeMgr.h"

namespace Game
{
	SceneMgr::SceneMgr()
		: m_CurScene(nullptr)
		, m_ToChangeScene(nullptr)
	{}
	SceneMgr::~SceneMgr()
	{
		Utility::DeleteMap<std::string, Scene*>(m_MapScenes);
	}
	void SceneMgr::Initalize()
	{
	}
	void SceneMgr::Update()
	{
		processPrevFrameRequest();

		m_CurScene->Update(TimeMgr::GetInst().DeltaTime());
	}
	void SceneMgr::PostUpdate()
	{
		m_CurScene->PostUpdate(TimeMgr::GetInst().DeltaTime());
	}
	void SceneMgr::Render()
	{
		m_CurScene->Render();
	}
	void SceneMgr::AddScene(Scene* const scene)
	{
		const std::string& sceneName = scene->GetName();
		auto iter = m_MapScenes.find(sceneName);
		if (iter != m_MapScenes.end())
			assert(0);
		m_MapScenes.insert(std::make_pair(sceneName, scene));
	}
	void SceneMgr::SetFirstScene(const std::string& sceneName)
	{
		if (m_CurScene)
			assert(0);

		auto iter = m_MapScenes.find(sceneName);
		if (iter == m_MapScenes.end())
			assert(0);

		m_CurScene = iter->second;
		m_CurScene->EnterScene();
	}
	void SceneMgr::RequestChangeScene(const std::string& sceneName)
	{
		if (m_ToChangeScene)
			assert(0);

		auto iter = m_MapScenes.find(sceneName);
		if (iter == m_MapScenes.end())
			assert(0);

		m_ToChangeScene = iter->second;
	}
	void SceneMgr::processPrevFrameRequest()
	{
		if (m_ToChangeScene)
		{
			m_CurScene->ExitScene();
			m_CurScene = m_ToChangeScene;
			m_CurScene->EnterScene();
			m_ToChangeScene = nullptr;
		}
	}
}
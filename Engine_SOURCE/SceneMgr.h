#pragma once
#include "Common.h"
namespace Game
{
	class Scene;
	class SceneMgr
	{
		SINGLE(SceneMgr)
	public:
		void Initalize();
		void Update();
		void PostUpdate();
		void Render();
		void AddScene(Scene* const scene);
		void SetFirstScene(const std::string& sceneName);
		void RequestChangeScene(const std::string& sceneName);
		Scene* GetCurScene() { assert(m_CurScene); return m_CurScene; }

	private:
		void processPrevFrameRequest();

	private:
		std::map<std::string, Scene*> m_MapScenes;
		Scene* m_CurScene;
		Scene* m_ToChangeScene;

	};
}



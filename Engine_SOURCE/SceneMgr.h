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
		void Render(HDC dc);
		void AddScene(Scene* const scene);

	private:
		std::map<std::string, Scene*> m_MapScenes;
		Scene* m_CurScene;

	};
}



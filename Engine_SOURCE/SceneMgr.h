#pragma once
#include "Common.h"
namespace Game
{
	class Scene;
	class SceneMgr
	{
		SINGLE(SceneMgr)
	public:
		void Initalize(UINT screenWidth, UINT screenHeight);
		void Update();
		void PostUpdate();
		void Render(HDC dc);

		void AddScene(Scene* const scene);
		void SetFirstScene(const std::string& sceneName);
		void RequestChangeScene(const std::string& sceneName);

		UINT GetScreenWidth() { return m_ScreenWidth; }
		UINT GetScreenHeight() { return m_ScreenHeight; }
		Scene* GetCurScene() { assert(m_CurScene); return m_CurScene; }

	private:
		void processPrevFrameRequest();

	private:
		std::map<std::string, Scene*> m_MapScenes;
		Scene* m_CurScene;
		Scene* m_ToChangeScene;

		UINT m_ScreenWidth;
		UINT m_ScreenHeight;

	};
}



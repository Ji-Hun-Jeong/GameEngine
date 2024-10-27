#pragma once
#include "Common.h"
namespace Game
{
	class SceneMgr
	{
		SINGLE(SceneMgr)
	public:
		void Initalize(UINT screenWidth, UINT screenHeight);
		void Update();
		void PostUpdate();
		void Render(HDC dc);

		void AddScene(class Scene* const scene);
		void SetFirstScene(const std::string& sceneName);
		void RequestChangeScene(const std::string& sceneName);

		UINT GetScreenWidth() { return m_ScreenWidth; }
		UINT GetScreenHeight() { return m_ScreenHeight; }
		class Scene* GetCurScene() { assert(m_CurScene); return m_CurScene; }

	private:
		void processPrevFrameRequest();

	private:
		std::map<std::string, class Scene*> m_MapScenes;
		class Scene* m_CurScene;
		class Scene* m_ToChangeScene;

		UINT m_ScreenWidth;
		UINT m_ScreenHeight;

	};
}



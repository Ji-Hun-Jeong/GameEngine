#include "Application.h"
#include "Bitmap.h"
#include "KeyMgr.h"
#include "MouseMgr.h"
#include "PathMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "CollisionMgr.h"

namespace Game
{
	Application::Application(HWND hwnd, UINT screenWidth, UINT screenHeight)
		: m_Hwnd(hwnd)
		, m_MainWindowDc(nullptr)
		, m_ScreenWidth(screenWidth)
		, m_ScreenHeight(screenHeight)
		, m_Run(true)
	{
		if (m_Hwnd == nullptr)
			assert(0);
		{
			//OPENFILENAMEA ofn;       // 구조체 선언
			//char szFile[260] = { 0 };  // 파일 이름을 저장할 버퍼

			//// OPENFILENAMEA 구조체 초기화
			//ZeroMemory(&ofn, sizeof(ofn));
			//ofn.lStructSize = sizeof(ofn);
			//ofn.hwndOwner = m_Hwnd;      // 소유자 윈도우 핸들, 현재 콘솔이므로 NULL
			//ofn.lpstrFile = szFile;    // 파일 이름 버퍼 지정
			//ofn.nMaxFile = sizeof(szFile);  // 버퍼 크기
			//ofn.lpstrFilter = "All Files\0*.*\0Text Files\0*.TXT\0";  // 파일 필터
			//ofn.nFilterIndex = 1;      // 필터 인덱스
			//ofn.lpstrFileTitle = NULL; // 파일 제목 버퍼
			//ofn.nMaxFileTitle = 0;
			//ofn.lpstrInitialDir = NULL; // 초기 디렉터리
			//ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;
			//if (GetSaveFileNameA(&ofn))
			//{
			//	int a = 1;
			//}
			//else
			//{
			//	int a = 1;
			//}
		}
		
		ShowWindow(m_Hwnd, SW_SHOWDEFAULT);
		UpdateWindow(m_Hwnd);

		m_MainWindowDc = GetDC(m_Hwnd);
		if (m_MainWindowDc)
			std::cout << "MainWindow DC Initalized!" << std::endl;
	}
	Application::~Application()
	{
		ReleaseDC(m_Hwnd, m_MainWindowDc);
	}
	bool Application::Run()
	{
		update();
		postUpdate();
		render();
		if (KeyMgr::GetInst().GetKeyState(eKeyType::Esc, eButtonState::Tap))
			m_Run = false;
		return m_Run;
	}

	void Application::Initalize()
	{
		PathMgr::GetInst().Initalize();
		TimeMgr::GetInst().Initailize();
		MouseMgr::GetInst().Initalize(m_Hwnd);
		SceneMgr::GetInst().Initalize(m_ScreenWidth, m_ScreenHeight);
	}
	void Application::update()
	{
		MouseMgr::GetInst().Update();
		KeyMgr::GetInst().Update();
		TimeMgr::GetInst().Update();

		CollisionMgr::GetInst().Update();
		SceneMgr::GetInst().Update();
	}
	void Application::postUpdate()
	{
		SceneMgr::GetInst().PostUpdate();
	}
	void Application::render()
	{
		SceneMgr::GetInst().Render(m_MainWindowDc);
	}
}
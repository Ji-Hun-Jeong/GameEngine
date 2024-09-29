#include "Application.h"
#include "MouseMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "PathMgr.h"
#include "Bitmap.h"

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
		SceneMgr::GetInst().Initalize(m_ScreenWidth, m_ScreenHeight);
	}
	void Application::update()
	{
		MouseMgr::GetInst().Update();
		KeyMgr::GetInst().Update();
		TimeMgr::GetInst().Update();
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
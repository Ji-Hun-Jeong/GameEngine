#include "Application.h"
#include "MouseMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "Bitmap.h"

namespace Game
{
	Application::Application(HWND hwnd, UINT screenWidth, UINT screenHeight)
		: m_Hwnd(hwnd)
		, m_ScreenWidth(screenWidth)
		, m_ScreenHeight(screenHeight)
		, m_MainWindowDc(nullptr)
		, m_Run(true)
	{
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
		Bitmap::s_MainWindowDc = m_MainWindowDc;
		Bitmap::s_ScreenWidth = m_ScreenWidth;
		Bitmap::s_ScreenHeight = m_ScreenHeight;
		TimeMgr::GetInst().Initailize();
		SceneMgr::GetInst().Initalize();
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
		SceneMgr::GetInst().Render();
		TimeMgr::GetInst().Render(m_MainWindowDc);
	}
}
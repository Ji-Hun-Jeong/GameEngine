#include "Application.h"
#include "EventMgr.h"

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
		DeleteDC(m_MainWindowDc);
	}
	bool Application::Run()
	{
		update();
		postUpdate();
		render();
		return m_Run;
	}

	void Application::Initalize()
	{
		Game::Event::EventMgr::GetInst().Initalize();
	}
	void Application::update()
	{
		Game::Event::EventMgr::GetInst().Update();
	}
	void Application::postUpdate()
	{

	}
	void Application::render()
	{
		m_GameObject.Render(m_MainWindowDc);
	}
}
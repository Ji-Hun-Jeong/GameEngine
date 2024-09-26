#include "Application.h"

namespace Game
{
	Application::Application(HWND hwnd, UINT screenWidth, UINT screenHeight)
		: m_Hwnd(hwnd)
		, m_ScreenWidth(screenWidth)
		, m_ScreenHeight(screenHeight)
		, m_MainWindowDc(nullptr)
	{
		ShowWindow(m_Hwnd, SW_SHOWDEFAULT);
		UpdateWindow(m_Hwnd);

		m_MainWindowDc = GetDC(m_Hwnd);
		if (m_MainWindowDc)
			std::cout << "Main DC Initalize!" << std::endl;
	}
	Application::~Application()
	{
		if (DeleteDC(m_MainWindowDc))
			std::cout << "Delete DC Success!" << std::endl;
	}
	void Application::Run()
	{
		update();
		postUpdate();
		render();
	}

	void Application::initalize()
	{

	}
	void Application::update()
	{

	}
	void Application::postUpdate()
	{

	}
	void Application::render()
	{
		m_GameObject.Render(m_MainWindowDc);
	}
}
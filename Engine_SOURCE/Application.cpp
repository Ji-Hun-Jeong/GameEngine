#include "Application.h"
#include "MouseMgr.h"
#include "KeyMgr.h"
#include "MouseEventReceiver.h"
#include "KeyEventReceiver.h"

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
		m_GameObject.AddComponent(new MouseEventReceiver);
		m_GameObject.AddComponent(new KeyEventReceiver);
	}
	void Application::update()
	{
		MouseMgr::GetInst().Update();
		KeyMgr::GetInst().Update();

		m_GameObject.Update();
	}
	void Application::postUpdate()
	{

	}
	void Application::render()
	{
		m_GameObject.Render(m_MainWindowDc);
	}
}
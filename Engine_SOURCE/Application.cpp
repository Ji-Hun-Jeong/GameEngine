#include "Application.h"
#include "MouseMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

namespace Game
{
	Application::Application(HWND hwnd, UINT screenWidth, UINT screenHeight)
		: m_Hwnd(hwnd)
		, m_ScreenWidth(screenWidth)
		, m_ScreenHeight(screenHeight)
		, m_MainWindowDc(nullptr)
		, m_BufferBitmap{}
		, m_BufferDc{}
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
		DeleteDC(m_BufferDc);
		DeleteObject(m_BufferBitmap);
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
		m_BufferBitmap = CreateCompatibleBitmap(m_MainWindowDc, m_ScreenWidth, m_ScreenHeight);
		m_BufferDc = CreateCompatibleDC(m_MainWindowDc);

		HBITMAP prevBitmap = static_cast<HBITMAP>(SelectObject(m_BufferDc, m_BufferBitmap));
		DeleteObject(prevBitmap);

		SceneMgr::GetInst().Initalize();
	}
	void Application::update()
	{
		MouseMgr::GetInst().Update();
		KeyMgr::GetInst().Update();
		SceneMgr::GetInst().Update();
	}
	void Application::postUpdate()
	{
		SceneMgr::GetInst().PostUpdate();
	}
	void Application::render()
	{
		SceneMgr::GetInst().Render(m_BufferDc);
		BitBlt(m_MainWindowDc, 0, 0, m_ScreenWidth, m_ScreenHeight, m_BufferDc, 0, 0, SRCCOPY);
	}
}
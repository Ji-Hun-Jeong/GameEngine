#include "TimeMgr.h"

namespace Game
{
	TimeMgr::TimeMgr()
		: m_CpuFrequency{}
		, m_PrevFrequency{}
		, m_CurrentFrequency{}
		, m_DeltaTimeValue(0.0f)
	{

	}
	TimeMgr::~TimeMgr()
	{

	}
	void TimeMgr::Initailize()
	{
		QueryPerformanceFrequency(&m_CpuFrequency);

		QueryPerformanceCounter(&m_PrevFrequency);
	}
	void TimeMgr::Update()
	{
		QueryPerformanceCounter(&m_CurrentFrequency);
		float differenceFrequency
			= static_cast<float>(m_CurrentFrequency.QuadPart - m_PrevFrequency.QuadPart);
		m_DeltaTimeValue = differenceFrequency / static_cast<float>(m_CpuFrequency.QuadPart);
		m_PrevFrequency.QuadPart = m_CurrentFrequency.QuadPart;
	}
	void TimeMgr::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += m_DeltaTimeValue;
		float fps = 1.0f / m_DeltaTimeValue;
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = static_cast<int>(wcsnlen_s(str, 50));
		TextOut(hdc, 0, 0, str, len);
	}
}
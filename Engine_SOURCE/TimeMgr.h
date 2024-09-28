#pragma once
#include "Common.h"
namespace Game
{
	class TimeMgr
	{
		SINGLE(TimeMgr)
	public:
		void Initailize();
		void Update();
		void Render(HDC hdc);
		float DeltaTime() { return m_DeltaTimeValue; }

	private:
		LARGE_INTEGER m_CpuFrequency;
		LARGE_INTEGER m_PrevFrequency;
		LARGE_INTEGER m_CurrentFrequency;
		float m_DeltaTimeValue;
	};
}



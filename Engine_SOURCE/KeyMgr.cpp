#include "KeyMgr.h"

namespace Game
{
	KeyMgr::KeyMgr()
		: m_ArrKeyStates{}
		, m_ArrPrevKeyClicked{}
		, m_ArrKeyValues
		{
			0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30,
			0x51, 0x57, 0x45, 0x52, 0x41, 0x53, 0x44, 0x46,
			0xA2, 0xA4, 0xA0
		}
	{

	}
	KeyMgr::~KeyMgr()
	{

	}
	void KeyMgr::Update()
	{
		for (UINT i = 0; i < (UINT)eKeyType::End; ++i)
		{
			if (GetAsyncKeyState(m_ArrKeyValues[i]) & 0x8000)
			{
				if (m_ArrPrevKeyClicked[i])
					m_ArrKeyStates[i] = eButtonState::Hold;
				else
					m_ArrKeyStates[i] = eButtonState::Tap;
				m_ArrPrevKeyClicked[i] = true;
			}
			else
			{
				if (m_ArrPrevKeyClicked[i])
					m_ArrKeyStates[i] = eButtonState::Released;
				else
					m_ArrKeyStates[i] = eButtonState::None;
				m_ArrPrevKeyClicked[i] = false;
			}
		}
	}
}

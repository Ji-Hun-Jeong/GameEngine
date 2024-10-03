#pragma once
#include "Common.h"
namespace Game
{
	enum class eKeyType
	{
		B1, B2, B3, B4, B5, B6, B7, B8, B9, B0,
		Q, W, E, R, A, S, D, F, Z,
		Left, Right, Up, Down, 
		Ctrl, Alt, Shift, Esc, End,
	};
	class KeyMgr
	{
		SINGLE(KeyMgr)
	public:
		void Update();
		bool GetKeyState(eKeyType keyType, eButtonState keyState)
		{ return m_ArrKeyStates[(UINT)keyType] == keyState; }

	private:
		eButtonState m_ArrKeyStates[(UINT)eKeyType::End];
		bool m_ArrPrevKeyClicked[(UINT)eKeyType::End];
		int m_ArrKeyValues[(UINT)eKeyType::End];

	};
}



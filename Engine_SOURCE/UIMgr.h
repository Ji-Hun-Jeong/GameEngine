#pragma once
#include "queue"
#include "Common.h"
namespace Game
{
	class UIMgr
	{
		SINGLE(UIMgr)
	public:
		void Update();

	private:
		class UI* getFocusUI(std::queue<class GameObject*>& uiQueue);

	private:
		UI* m_CurFocusUI;
		UI* m_PrevFocusUI;

	};
}



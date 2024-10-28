#pragma once
#include "UI.h"
namespace Game
{
	class MainUI : public UI
	{
		CLONE(UI, MainUI)
	public:
		MainUI();
		MainUI(const MainUI& other) = default;
		~MainUI();

	public:

	};
}



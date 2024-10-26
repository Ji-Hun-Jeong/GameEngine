#pragma once
#include "UI.h"
namespace Game
{
	class MainUI : public UI
	{
		CLONE(GameObject, MainUI)
	public:
		MainUI();
		MainUI(const MainUI& other) = default;
		~MainUI();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera) override;
		void Render(HDC dc) override;
		void EnterMouse() override;
		void OnMouse() override;
		void ExitMouse() override;
	};
}



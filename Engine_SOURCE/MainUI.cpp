#include "MainUI.h"
#include "TransformComponent.h"

namespace Game
{
	MainUI::MainUI()
		: UI("MainUI")
	{
	}
	MainUI::~MainUI()
	{
	}
	void MainUI::Update(float dt)
	{
		UI::Update(dt);

	}
	void MainUI::PostUpdate(float dt, Camera* const curCamera)
	{
		UI::PostUpdate(dt, curCamera);
	}
	void MainUI::Render(HDC dc)
	{
		UI::Render(dc);
	}
	void MainUI::EnterMouse()
	{
		UI::EnterMouse();
	}
	void MainUI::OnMouse()
	{
		UI::OnMouse();
	}
	void MainUI::ExitMouse()
	{
		UI::ExitMouse();
	}
}
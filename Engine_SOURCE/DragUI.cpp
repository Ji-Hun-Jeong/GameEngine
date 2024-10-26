#include "DragUI.h"
#include "MouseUIMove.h"
#include "TransformComponent.h"

namespace Game
{
	DragUI::DragUI()
		: UI("DragUI")
	{
	}
	DragUI::~DragUI()
	{
	}
	void DragUI::Update(float dt)
	{
		UI::Update(dt);
	}
	void DragUI::PostUpdate(float dt, Camera* const curCamera)
	{
		UI::PostUpdate(dt, curCamera);
	}
	void DragUI::Render(HDC dc)
	{
		UI::Render(dc);
	}
	void DragUI::EnterMouse()
	{
		UI::EnterMouse();
	}
	void DragUI::OnMouse()
	{
		UI::OnMouse();
	}
	void DragUI::ExitMouse()
	{
		UI::ExitMouse();
	}
}
#pragma once
#include "UI.h"
namespace Game
{
	class DragUI : public UI
	{
		CLONE(GameObject, DragUI)
	public:
		DragUI();
		DragUI(const DragUI& other) = default;
		~DragUI();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera) override;
		void Render(HDC dc) override;
		void EnterMouse() override;
		void OnMouse() override;
		void ExitMouse() override;
	};
}



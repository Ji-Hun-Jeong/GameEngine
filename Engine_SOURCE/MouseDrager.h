#pragma once
#include "GameObject.h"
namespace Game
{
	class MouseDrager :	public GameObject
	{
	public:
		MouseDrager();
		~MouseDrager();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera);
		void Render(HDC dc) override;
		bool IsCompleteMakeRect() { return m_CompleteMakeRect; }
		const Gdiplus::Rect& GetDragedRect() { return m_DragedRect; }

	private:
		Gdiplus::Rect m_DragedRect;
		bool m_CompleteMakeRect;
	};
}



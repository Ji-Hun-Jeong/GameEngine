#pragma once
#include "MoveComponent.h"
namespace Game
{
	class MouseDrag : public MoveComponent
	{
		CLONE(MoveComponent, MouseDrag)
	public:
		MouseDrag();
		MouseDrag(const MouseDrag& other);
		~MouseDrag();

	public:
		void Move(float dt) override;

		bool IsStartDraging() { return m_StartDrag; }
		bool IsReleased() { return m_FinishDrag; }

	private:
		Math::Vector2 m_FirstClickPos;
		Math::Vector2 m_DragingPos;
		bool m_StartDrag;
		bool m_FinishDrag;
	};
}



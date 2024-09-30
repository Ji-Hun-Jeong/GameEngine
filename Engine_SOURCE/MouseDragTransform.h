#pragma once
#include "TransformComponent.h"
namespace Game
{
	class MouseDragTransform : public TransformComponent
	{
	public:
		MouseDragTransform(GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		~MouseDragTransform();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, const TransformComponent* const curCameraTransform) override;
		bool IsStartDraging() { return m_StartDrag; }
		bool IsReleased() { return m_FinishDrag; }

	private:
		Math::Vector2 m_FirstClickPos;
		Math::Vector2 m_DragingPos;
		bool m_StartDrag;
		bool m_FinishDrag;
	};
}



#pragma once
#include "TransformComponent.h"
namespace Game
{
	class MouseDragTransform : public TransformComponent
	{
		CLONE(TransformComponent, MouseDragTransform)
	public:
		explicit MouseDragTransform(const Math::Vector2& pos, const Math::Vector2& size);
		MouseDragTransform(const MouseDragTransform&) = default;
		~MouseDragTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
		
	};
}



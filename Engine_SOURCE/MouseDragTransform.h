#pragma once
#include "TransformComponent.h"
namespace Game
{
	class MouseDragTransform : public TransformComponent
	{
	public:
		explicit MouseDragTransform(GameObject* owner, const Math::Vector2& pos, const Math::Vector2& size);
		~MouseDragTransform();

	public:
		void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) override;
		
	};
}



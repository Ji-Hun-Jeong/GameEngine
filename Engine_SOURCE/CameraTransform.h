#pragma once
#include "TransformComponent.h"
namespace Game
{
	class CameraTransform : public TransformComponent
	{
	public:
		CameraTransform(GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		~CameraTransform();

	public:
		void Update(float dt) override;

	};
}


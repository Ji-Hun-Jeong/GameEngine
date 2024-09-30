#pragma once
#include "RenderComponent.h"
namespace Game
{
	class BackGroundRenderer : public RenderComponent
	{
	public:
		explicit BackGroundRenderer(GameObject* const owner);
		~BackGroundRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;
		void Render(HDC dc, const Math::Vector2& finalPos, const Math::Vector2& size) override;

	};
}



#pragma once
#include "RenderComponent.h"
namespace Game
{
	class SpriteRenderer : public RenderComponent
	{
		CLONE(RenderComponent, SpriteRenderer)
	public:
		SpriteRenderer();
		SpriteRenderer(const SpriteRenderer&) = default;
		~SpriteRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;
	};
}



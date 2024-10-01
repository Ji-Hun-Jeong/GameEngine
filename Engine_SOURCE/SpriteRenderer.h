#pragma once
#include "RenderComponent.h"
namespace Game
{
	class SpriteRenderer : public RenderComponent
	{
	public:
		explicit SpriteRenderer(GameObject* const owner);
		~SpriteRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;
	};
}



#pragma once
#include "RenderComponent.h"
namespace Game
{
	class BasicRenderer : public RenderComponent
	{
	public:
		explicit BasicRenderer(GameObject* const owner);
		~BasicRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;
		void Render(HDC dc, const Math::Vector2& finalPos, const Math::Vector2& size) override;

	};
}



#pragma once
#include "RenderComponent.h"
namespace Game
{
	class BasicRenderer : public RenderComponent
	{
		CLONE(RenderComponent, BasicRenderer)
	public:
		BasicRenderer();
		BasicRenderer(const BasicRenderer&) = default;
		~BasicRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;

	};
}



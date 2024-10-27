#pragma once
#include "RenderComponent.h"

namespace Game
{
	class BackGroundRenderer : public RenderComponent
	{
		CLONE(RenderComponent, BackGroundRenderer)
	public:
		explicit BackGroundRenderer();
		BackGroundRenderer(const BackGroundRenderer&) = default;
		~BackGroundRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;

	};
}



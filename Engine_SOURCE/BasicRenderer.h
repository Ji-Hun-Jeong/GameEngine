#pragma once
#include "RenderComponent.h"
namespace Game
{
	class BasicRenderer : public RenderComponent
	{
	public:
		BasicRenderer(GameObject* const owner);
		~BasicRenderer();

	public:
		void Render(HDC dc, TransformComponent* const transform) override;

	};
}



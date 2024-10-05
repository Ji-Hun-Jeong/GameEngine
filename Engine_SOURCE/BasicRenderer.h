#pragma once
#include "RenderComponent.h"
namespace Game
{
	class BasicRenderer : public RenderComponent
	{
	public:
		explicit BasicRenderer(GameObject* owner);
		~BasicRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;

	};
}



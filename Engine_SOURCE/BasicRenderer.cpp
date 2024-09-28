#include "BasicRenderer.h"
#include "TransformComponent.h"

namespace Game
{
	BasicRenderer::BasicRenderer(GameObject* const owner)
		: RenderComponent("BasicRenderer", owner)
	{	}
	BasicRenderer::~BasicRenderer()
	{
	}
	void BasicRenderer::Render(HDC dc, TransformComponent* const transform)
	{
		const Math::Vector2& ownerPos = transform->GetPos();
		const Math::Vector2& ownerSize = transform->GetSize();

		RECT renderRect = GetRectangle(ownerPos, ownerSize);

		Rectangle(dc, renderRect.left, renderRect.top, renderRect.right, renderRect.bottom);
	}
}
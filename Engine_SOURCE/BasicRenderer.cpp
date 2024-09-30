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
	void BasicRenderer::Render(HDC dc, const TransformComponent* const transform)
	{
		const Math::Vector2& ownerPos = transform->GetFinalPos();
		const Math::Vector2& ownerSize = transform->GetSize();

		RECT renderRect = TransformMYC(ownerPos, ownerSize);

		Rectangle(dc, renderRect.left, renderRect.top, renderRect.right, renderRect.bottom);
	}
}
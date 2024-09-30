#include "BasicRenderer.h"
#include "TransformComponent.h"

namespace Game
{
	BasicRenderer::BasicRenderer(GameObject* const owner)
		: RenderComponent("BasicRenderer", owner)
	{}
	BasicRenderer::~BasicRenderer()
	{
	}
	void BasicRenderer::Render(HDC dc, const TransformComponent* const transform)
	{
		const Math::Vector2& ownerPos = transform->GetFinalPos();
		const Math::Vector2& ownerSize = transform->GetSize();
		std::cout << "Pos : ";
		ownerPos.Print();
		std::cout << "Size : ";
		ownerSize.Print();

		RECT renderRect = TransformMYC(ownerPos, ownerSize);

		Rectangle(dc, renderRect.left, renderRect.top, renderRect.right, renderRect.bottom);
	}
	void BasicRenderer::Render(HDC dc, const Math::Vector2& finalPos, const Math::Vector2& size)
	{
		RECT renderRect = TransformMYC(finalPos, size);

		Rectangle(dc, renderRect.left, renderRect.top, renderRect.right, renderRect.bottom);
	}
}
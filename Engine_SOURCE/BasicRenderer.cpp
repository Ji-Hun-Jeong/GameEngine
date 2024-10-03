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
		Gdiplus::Rect finalRect = transform->GetFinalRectInMYC();
		int right = finalRect.X + finalRect.Width;
		int bottom = finalRect.Y + finalRect.Height;
		Rectangle(dc, finalRect.X, finalRect.Y, right, bottom);
	}

}
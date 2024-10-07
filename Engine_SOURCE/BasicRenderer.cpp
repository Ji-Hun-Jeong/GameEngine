#include "BasicRenderer.h"
#include "TransformComponent.h"

namespace Game
{
	BasicRenderer::BasicRenderer()
		: RenderComponent()
	{}
	BasicRenderer::~BasicRenderer()
	{
	}
	void BasicRenderer::Render(HDC dc, const TransformComponent* const transform)
	{
		Gdiplus::Graphics graphics(dc);
		Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 0), 1);
		Gdiplus::Rect finalRect = transform->GetFinalRectInMYC();
		int right = finalRect.X + finalRect.Width;
		int bottom = finalRect.Y + finalRect.Height;
		graphics.DrawRectangle(&pen, finalRect);
	}

}
#include "BasicRenderer.h"
#include "TransformComponent.h"

namespace Game
{
	BasicRenderer::BasicRenderer()
		: RenderComponent()
		, m_Color(255, 0, 0, 0)
		, m_Width(1.0f)
	{}
	BasicRenderer::~BasicRenderer()
	{
	}
	void BasicRenderer::Render(HDC dc, const TransformComponent* const transform)
	{
		Gdiplus::Graphics graphics(dc);
		Gdiplus::Pen pen(m_Color, m_Width);
		Gdiplus::Rect finalRect = transform->GetFinalRectInMYC();
		int right = finalRect.X + finalRect.Width;
		int bottom = finalRect.Y + finalRect.Height;
		graphics.DrawRectangle(&pen, finalRect);
	}

}
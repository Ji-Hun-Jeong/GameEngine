#include "BackGroundRenderer.h"

namespace Game
{
	BackGroundRenderer::BackGroundRenderer(GameObject* owner)
		: RenderComponent(owner)
	{
	}
	BackGroundRenderer::~BackGroundRenderer()
	{
	}
	void BackGroundRenderer::Render(HDC dc, const TransformComponent* const transform)
	{
		assert(m_Texture);
		Gdiplus::Rect finalRect = transform->GetFinalRectInMYC();

		BitBlt(dc, finalRect.X, finalRect.Y, finalRect.Width, finalRect.Height
			, m_Texture->GetBitmapDc(), 0, 0, SRCCOPY);
	}
}

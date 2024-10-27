#include "SpriteRenderer.h"

namespace Game
{
	SpriteRenderer::SpriteRenderer()
		: RenderComponent()
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Render(HDC dc, const TransformComponent* const transform)
	{
		assert(m_Texture);
		Gdiplus::Rect finalRect = transform->GetFinalRectInMYC();
		TransparentBlt(dc, finalRect.X, finalRect.Y, finalRect.Width, finalRect.Height
			, m_Texture->GetBitmapDc()
			, 0, 0
			, m_Texture->GetWidth(), m_Texture->GetHeight(), MAGENTA);

	}
}


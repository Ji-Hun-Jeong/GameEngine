#include "SpriteRenderer.h"
#include "Texture.h"

namespace Game
{
	SpriteRenderer::SpriteRenderer(GameObject* const owner)
		: RenderComponent("Sprite", owner)
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


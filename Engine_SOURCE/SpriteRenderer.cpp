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
		const Math::Vector2& pos = transform->GetPos();
		const Math::Vector2& size = transform->GetSize();
		UINT sizeX = static_cast<UINT>(size.x);
		UINT sizeY = static_cast<UINT>(size.y);
		RECT newRect = TransformMYC(pos, size);

		TransparentBlt(dc, newRect.left, newRect.top, sizeX, sizeY
			, m_Texture->GetBitmapDc()
			, 0, 0
			, m_Texture->GetWidth(), m_Texture->GetHeight(), MAGENTA);

	}
}


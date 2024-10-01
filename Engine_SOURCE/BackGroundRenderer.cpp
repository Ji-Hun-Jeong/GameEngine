#include "BackGroundRenderer.h"

namespace Game
{
	BackGroundRenderer::BackGroundRenderer(GameObject* const owner)
		: RenderComponent("BackGroundRenderer", owner)
	{
	}
	BackGroundRenderer::~BackGroundRenderer()
	{
	}
	void BackGroundRenderer::Render(HDC dc, const TransformComponent* const transform)
	{
		assert(m_Texture);
		const Math::Vector2& pos = transform->GetFinalPos();
		const Math::Vector2& size = transform->GetSize();
		int left = static_cast<int>(pos.x);
		int top = static_cast<int>(pos.y);
		UINT sizeX = static_cast<UINT>(size.x);
		UINT sizeY = static_cast<UINT>(size.y);
		RECT newRect = TransformMYC(pos, size);

		BitBlt(dc, left, top, sizeX, sizeY
			, m_Texture->GetBitmapDc(), 0, 0, SRCCOPY);
	}
}

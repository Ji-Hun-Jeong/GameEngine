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
		const Math::Vector2& pos = transform->GetFinalPos();
		const Math::Vector2& size = transform->GetSize();
		UINT sizeX = static_cast<UINT>(size.x);
		UINT sizeY = static_cast<UINT>(size.y);
		RECT newRect = TransformMYC(pos, size);

		BitBlt(dc, 0, 0, sizeX, sizeY
			, m_Texture->GetBitmapDc(), 0, 0, SRCCOPY);
	}
}

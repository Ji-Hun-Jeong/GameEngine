#include "SpriteRenderer.h"
#include "TransformComponent.h"

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
		Gdiplus::Image* image = Gdiplus::Image::FromFile(L"../Resource/Texture/Test.png");
		Gdiplus::Graphics g(dc);
		RECT rect = RenderComponent::GetRectangle(transform->GetPos(), transform->GetSize());
		Gdiplus::Rect r(rect.left, rect.top, transform->GetSize().x, transform->GetSize().y);
		g.DrawImage(image, r);
	}
}


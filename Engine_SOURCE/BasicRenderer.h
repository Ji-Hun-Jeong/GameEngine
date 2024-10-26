#pragma once
#include "RenderComponent.h"
namespace Game
{
	class BasicRenderer : public RenderComponent
	{
		CLONE(RenderComponent, BasicRenderer)
	public:
		BasicRenderer();
		BasicRenderer(const BasicRenderer&) = default;
		~BasicRenderer();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;

		void SetColor(const Gdiplus::Color& color) { m_Color = color; }
		void SetWidth(float width) { m_Width = width; }

	private:
		Gdiplus::Color m_Color;
		float m_Width;
	};
}



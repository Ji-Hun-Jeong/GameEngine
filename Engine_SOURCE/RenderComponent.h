#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "Texture.h"
namespace Game
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent(const std::string& name, GameObject* const owner);
		virtual ~RenderComponent();

	public:
		virtual void Render(HDC dc, const TransformComponent* const transform) = 0;

		void SetTexture(const std::string& textureName);
	protected:
		RECT GetRectangle(const Math::Vector2& pos, const Math::Vector2& size);

		Texture* m_Texture;
	};
}



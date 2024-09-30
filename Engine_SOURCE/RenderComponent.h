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
		virtual void Render(HDC dc, const Math::Vector2& finalPos, const Math::Vector2& size) = 0;

		void SetTexture(const std::string& textureName);
		Math::Vector2 GetTextureSize();
	protected:
		Texture* m_Texture;
	};
}



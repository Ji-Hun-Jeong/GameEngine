#pragma once
#include "Component.h"
#include "TransformComponent.h"
#include "Texture.h"
namespace Game
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent();
		RenderComponent(const RenderComponent& other);
		virtual ~RenderComponent();

	public:
		virtual RenderComponent* GetClone() const = 0;
		virtual void Render(HDC dc, const TransformComponent* const transform) = 0;

		void SetTexture(const std::string& textureName);
		Math::Vector2 GetTextureSize();

	protected:
		Texture* m_Texture;

	};
}



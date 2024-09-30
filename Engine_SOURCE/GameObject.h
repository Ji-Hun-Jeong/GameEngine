#pragma once
#include "Common.h"
#include "Entity.h"

namespace Game
{
	class Component;
	class TransformComponent;
	class RenderComponent;
	class Camera;
	class GameObject : public Entity
	{
	public:
		GameObject(const std::string& name);
		virtual ~GameObject() = 0;

	public:
		virtual void Update(float dt);
		virtual void PostUpdate(float dt, Camera* const curCamera);
		virtual void Render(HDC dc);
		
		void SetTransformComponent(TransformComponent* const transformComponent);
		void SetRenderComponent(RenderComponent* const renderComponent);
		void SetTexture(const std::string& textureName);
		void SetPos(const Math::Vector2& pos);
		void SetSize(const Math::Vector2& size);
		void SetSizeFromTexture();

		const Math::Vector2& GetPos();
		const Math::Vector2& GetFinalPos();
		const Math::Vector2& GetSize();

		void AddComponent(Component* const component);
		template <typename T>
		T GetComponent(const std::string& componentName);

	protected:
		TransformComponent* m_TransformComponent;
		RenderComponent* m_RenderComponent;

	};

	template <typename T>
	T GameObject::GetComponent(const std::string& componentName)
	{
		
	}
}


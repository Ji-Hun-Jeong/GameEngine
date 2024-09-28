#pragma once
#include "Common.h"
#include "Entity.h"

namespace Game
{
	class Component;
	class TransformComponent;
	class RenderComponent;
	class GameObject : public Entity
	{
	public:
		GameObject(const std::string& name);
		virtual ~GameObject() = 0;

	public:
		virtual void Update(float dt);
		virtual void PostUpdate(float dt);
		virtual void Render(HDC dc);
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


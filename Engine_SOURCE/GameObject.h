#pragma once
#include "Common.h"
#include "Component.h"
namespace Game
{
	class GameObject : public Entity
	{
	public:
		GameObject(const std::string& name);
		virtual ~GameObject();

	public:
		virtual void Update();
		virtual void PostUpdate();
		virtual void Render(HDC dc);
		void AddComponent(Component* const component);

		template <typename T>
		T GetComponent(const std::string& componentName);

	protected:
		std::map<std::string, Component*> m_MapComponents;
	};

	template <typename T>
	T GameObject::GetComponent(const std::string& componentName)
	{
		auto iter = m_MapComponents.find(componentName);
		if (iter == m_MapComponents.end())
			assert(0);
		return dynamic_cast<T>(iter->second);
	}
}


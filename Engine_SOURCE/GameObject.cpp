#include "GameObject.h"

namespace Game
{
	GameObject::GameObject()
	{
		
	}
	GameObject::~GameObject()
	{
		for (auto iter = m_MapComponents.begin(); iter != m_MapComponents.end(); ++iter)
			delete iter->second;
	}
	void GameObject::AddComponent(Component* const component)
	{
		const std::string& name = component->GetName();
		auto iter = m_MapComponents.find(name);
		if (iter != m_MapComponents.end())
			assert(0);
		m_MapComponents.insert(std::make_pair(name, component));
	}

	void GameObject::Update()
	{
		for (auto iter = m_MapComponents.begin(); iter != m_MapComponents.end(); ++iter)
			iter->second->DoSomething(this);
	}
	void GameObject::Render(HDC dc)
	{
		Rectangle(dc, 100, 100, 200, 200);
	}
}

#include "GameObject.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

namespace Game
{
	GameObject::GameObject(const std::string& name)
		: Entity(name)
		, m_TransformComponent(nullptr)
		, m_RenderComponent(nullptr)
	{
		
	}
	GameObject::~GameObject()
	{
		
	}
	void GameObject::AddComponent(Component* const component)
	{
		
	}

	void GameObject::Update()
	{
		if (m_TransformComponent)
			m_TransformComponent->Update();
	}
	void GameObject::PostUpdate()
	{

	}
	void GameObject::Render(HDC dc)
	{
		if (m_RenderComponent)
			m_RenderComponent->Render(dc, m_TransformComponent);
	}
}

#include "GameObject.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Camera.h"

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
		if (m_TransformComponent)
			delete m_TransformComponent;
		if (m_RenderComponent)
			delete m_RenderComponent;
	}

	void GameObject::AddComponent(Component* const component)
	{
		
	}

	void GameObject::SetTransformComponent(TransformComponent* const transformComponent)
	{
		if (m_TransformComponent)
			delete m_TransformComponent;
		m_TransformComponent = transformComponent;
	}

	void GameObject::SetRenderComponent(RenderComponent* const renderComponent)
	{
		if (m_RenderComponent)
			delete m_RenderComponent;
		m_RenderComponent = renderComponent;
	}

	void GameObject::SetTexture(const std::string& textureName)
	{
		assert(m_RenderComponent);
		m_RenderComponent->SetTexture(textureName);
	}

	void GameObject::SetPos(const Math::Vector2& pos)
	{
		assert(m_TransformComponent);
		m_TransformComponent->SetPos(pos);
	}

	void GameObject::SetSize(const Math::Vector2& size)
	{
		assert(m_TransformComponent);
		m_TransformComponent->SetSize(size);
	}

	void GameObject::SetSizeFromTexture()
	{
		assert(m_RenderComponent);
		this->SetSize(m_RenderComponent->GetTextureSize());
	}
	const Math::Vector2& GameObject::GetPos()
	{
		assert(m_TransformComponent);
		return m_TransformComponent->GetPos();
	}

	const Math::Vector2& GameObject::GetFinalPos()
	{
		assert(m_TransformComponent);
		return m_TransformComponent->GetFinalPos();
	}

	const Math::Vector2& GameObject::GetSize()
	{
		assert(m_TransformComponent);
		return m_TransformComponent->GetSize();
	}

	void GameObject::Update(float dt)
	{
		if (m_TransformComponent)
			m_TransformComponent->Update(dt);
	}

	void GameObject::PostUpdate(float dt, Camera* const curCamera)
	{
		assert(curCamera);

		GameObject* const p = curCamera;

		if (m_TransformComponent)
			m_TransformComponent->PostUpdate(dt, p->m_TransformComponent);
	}

	void GameObject::Render(HDC dc)
	{
		if (m_RenderComponent && m_TransformComponent)
			m_RenderComponent->Render(dc, m_TransformComponent);
	}
}

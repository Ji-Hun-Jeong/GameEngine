#include "GameObject.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Camera.h"
#include "Collider.h"

namespace Game
{
	GameObject::GameObject(const std::string& name)
		: Entity(name)
		, m_TransformComponent(nullptr)
		, m_RenderComponent(nullptr)
		, m_Collider(nullptr)
	{
		
	}

	GameObject::~GameObject()
	{
		if (m_TransformComponent)
			delete m_TransformComponent;
		if (m_RenderComponent)
			delete m_RenderComponent;
		if (m_Collider)
			delete m_Collider;
	}

	void GameObject::SetTransformComponent(TransformComponent* const transformComponent)
	{
		assert(transformComponent);

		if (m_TransformComponent)
			delete m_TransformComponent;
		m_TransformComponent = transformComponent;
	}

	void GameObject::SetRenderComponent(RenderComponent* const renderComponent)
	{
		assert(renderComponent);

		if (m_RenderComponent)
			delete m_RenderComponent;
		m_RenderComponent = renderComponent;
	}
	void GameObject::SetCollider(Collider* const collider)
	{
		assert(m_TransformComponent);

		if (m_Collider)
			delete m_Collider;
		m_Collider = collider;
	}

	void GameObject::SetTexture(const std::string& textureName)
	{
		m_RenderComponent->SetTexture(textureName);
	}

	void GameObject::SetPos(const Math::Vector2& pos)
	{
		m_TransformComponent->SetPos(pos);
	}

	void GameObject::SetSize(const Math::Vector2& size)
	{
		m_TransformComponent->SetSize(size);
	}

	void GameObject::SetSizeFromTexture()
	{
		this->SetSize(m_RenderComponent->GetTextureSize());
	}
	const Math::Vector2& GameObject::GetPos()
	{
		return m_TransformComponent->GetPos();
	}

	const Math::Vector2& GameObject::GetFinalPos()
	{
		return m_TransformComponent->GetFinalPos();
	}

	const Math::Vector2& GameObject::GetSize()
	{
		return m_TransformComponent->GetSize();
	}

	Gdiplus::Rect GameObject::GetFinalRectInMYC() const
	{
		return m_TransformComponent->GetFinalRectInMYC();
	}

	void GameObject::Update(float dt)
	{
		if (m_TransformComponent)
			m_TransformComponent->Transform(dt);
	}

	void GameObject::PostUpdate(float dt, Camera* const curCamera)
	{
		assert(curCamera);
		
		GameObject* const p = curCamera;

		if (m_TransformComponent)
			m_TransformComponent->TransformByCamera(dt, p->m_TransformComponent);

		if (m_Collider)
			m_Collider->Update(dt, m_TransformComponent);
	}

	void GameObject::Render(HDC dc)
	{
		if (m_RenderComponent && m_TransformComponent)
			m_RenderComponent->Render(dc, m_TransformComponent);

		if (m_Collider)
			m_Collider->Render(dc);
	}
}

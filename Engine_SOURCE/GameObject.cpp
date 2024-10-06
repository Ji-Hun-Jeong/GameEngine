#include "GameObject.h"
#include "MoveComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Camera.h"
#include "Collider.h"
#include "RigidBody.h"

namespace Game
{
	GameObject::GameObject(const std::string& name)
		: Entity(name)
		, m_MoveComponent(nullptr)
		, m_TransformComponent(nullptr)
		, m_RenderComponent(nullptr)
	{
	}

	GameObject::~GameObject()
	{
		Utility::DeleteMap<std::string, Component*>(m_MapComponents);
	}

	void GameObject::SetMoveComponent(MoveComponent* const moveComponent)
	{
		assert(moveComponent);
		if (m_MoveComponent)
			delete m_MoveComponent;
		m_MoveComponent = moveComponent;
		m_MapComponents.insert_or_assign(m_MoveComponent->GetName(), m_MoveComponent);
	}

	void GameObject::SetRigidBody(RigidBody* const rigidBody)
	{
		assert(rigidBody);
		if (m_RigidBody)
			delete m_RigidBody;
		m_RigidBody = rigidBody;
		m_MapComponents.insert_or_assign(m_RigidBody->GetName(), m_RigidBody);
	}

	void GameObject::SetTransformComponent(TransformComponent* const transformComponent)
	{
		assert(transformComponent);
		if (m_TransformComponent)
			delete m_TransformComponent;
		m_TransformComponent = transformComponent;
		m_MapComponents.insert_or_assign(m_TransformComponent->GetName(), m_TransformComponent);
	}

	void GameObject::SetRenderComponent(RenderComponent* const renderComponent)
	{
		assert(renderComponent);
		if (m_RenderComponent)
			delete m_RenderComponent;
		m_RenderComponent = renderComponent;
		m_MapComponents.insert_or_assign(m_RenderComponent->GetName(), m_RenderComponent);
	}
	void GameObject::AddCollider(Collider* const collider)
	{
		assert(m_TransformComponent);
		assert(collider);
		auto iter = m_MapComponents.find(collider->GetName());
		if (iter != m_MapComponents.end())
		{
			for (auto mCollider : m_VecColliders)
			{
				if (mCollider->GetName() == collider->GetName())
				{
					delete mCollider;
					mCollider = collider;
				}
			}
		}
		else
		{
			m_VecColliders.push_back(collider);
		}
		m_MapComponents.insert_or_assign(collider->GetName(), collider);
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

	const Math::Vector2& GameObject::GetPos() const
	{
		return m_TransformComponent->GetPos();
	}

	const Math::Vector2& GameObject::GetFinalPos() const
	{
		return m_TransformComponent->GetFinalPos();
	}

	const Math::Vector2& GameObject::GetSize() const
	{
		return m_TransformComponent->GetSize();
	}

	Gdiplus::Rect GameObject::GetFinalRectInMYC() const
	{
		return m_TransformComponent->GetFinalRectInMYC();
	}

	void GameObject::Update(float dt)
	{
		if (m_MoveComponent)
			m_MoveComponent->Move(dt);
		if (m_RigidBody)
			m_RigidBody->Update(dt);
	}

	void GameObject::PostUpdate(float dt, Camera* const curCamera)
	{
		assert(curCamera);

		TransformComponent* const cameraTransform = curCamera->GetComponent<TransformComponent*>("Transform");

		assert(cameraTransform);

		if (m_TransformComponent)
			m_TransformComponent->TransformByCamera(dt, cameraTransform);

		for (auto mCollider : m_VecColliders)
		{
			if (mCollider)
				mCollider->Update(dt, m_TransformComponent);
		}
	}

	void GameObject::Render(HDC dc)
	{
		if (m_RenderComponent && m_TransformComponent)
			m_RenderComponent->Render(dc, m_TransformComponent);

		for (auto mCollider : m_VecColliders)
		{
			if (mCollider)
				mCollider->Render(dc);
		}
	}
}

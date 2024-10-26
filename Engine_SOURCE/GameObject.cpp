#include "GameObject.h"
#include "MoveComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "Camera.h"
#include "Collider.h"
#include "RigidBody.h"
#include "StateController.h"

namespace Game
{
	GameObject::GameObject(const std::string& name)
		: Entity(name)
		, m_VecColliders()
		, m_MoveComponent(nullptr)
		, m_RigidBody(nullptr)
		, m_StateController(nullptr)
		, m_TransformComponent(nullptr)
		, m_RenderComponent(nullptr)
	{
	}

	GameObject::GameObject(const GameObject& other)
		: Entity(other)
		, m_VecColliders()
		, m_MoveComponent(nullptr)
		, m_RigidBody(nullptr)
		, m_StateController(nullptr)
		, m_TransformComponent(nullptr)
		, m_RenderComponent(nullptr)
	{
		if (other.m_MoveComponent)
			SetMoveComponent(other.m_MoveComponent->GetClone());
		if (other.m_RigidBody)
			SetRigidBody(other.m_RigidBody->GetClone());
		if (other.m_StateController)
			SetStateController(other.m_StateController->GetClone());
		if (other.m_TransformComponent)
			SetTransformComponent(other.m_TransformComponent->GetClone());
		if (other.m_RenderComponent)
			SetRenderComponent(other.m_RenderComponent->GetClone());

		m_VecColliders.reserve(other.m_VecColliders.size());
		for (size_t i = 0; i < other.m_VecColliders.size(); ++i)
		{
			AddCollider(other.m_VecColliders[i]->GetClone());
		}
	}

	GameObject::~GameObject()
	{
		Utility::DeleteMap<std::string, Component*>(m_MapComponents);
	}

	void GameObject::SetMoveComponent(MoveComponent* const moveComponent)
	{
		if (m_MoveComponent)
			delete m_MoveComponent;
		m_MoveComponent = moveComponent;
		m_MoveComponent->SetOwner(this);
		m_MapComponents.insert_or_assign(m_MoveComponent->GetName(), m_MoveComponent);
	}

	void GameObject::SetRigidBody(RigidBody* const rigidBody)
	{
		if (m_RigidBody)
			delete m_RigidBody;
		m_RigidBody = rigidBody;
		m_RigidBody->SetOwner(this);
		m_MapComponents.insert_or_assign(m_RigidBody->GetName(), m_RigidBody);
	}

	void GameObject::SetStateController(StateController* const stateController)
	{
		if (m_StateController)
			delete m_StateController;
		m_StateController = stateController;
		m_StateController->SetOwner(this);
		m_MapComponents.insert_or_assign(m_StateController->GetName(), m_StateController);
	}

	void GameObject::SetTransformComponent(TransformComponent* const transformComponent)
	{
		if (m_TransformComponent)
			delete m_TransformComponent;
		m_TransformComponent = transformComponent;
		m_TransformComponent->SetOwner(this);
		m_MapComponents.insert_or_assign(m_TransformComponent->GetName(), m_TransformComponent);
	}

	void GameObject::SetRenderComponent(RenderComponent* const renderComponent)
	{
		if (m_RenderComponent)
			delete m_RenderComponent;
		m_RenderComponent = renderComponent;
		m_RenderComponent->SetOwner(this);
		m_MapComponents.insert_or_assign(m_RenderComponent->GetName(), m_RenderComponent);
	}
	void GameObject::AddCollider(Collider* const collider)
	{
		assert(m_TransformComponent);
		collider->SetOwner(this);
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

	void GameObject::SetOffset(const Math::Vector2& offset)
	{
		m_TransformComponent->SetOffset(offset);
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

	const Math::Vector2& GameObject::GetOffset() const
	{
		return m_TransformComponent->GetOffset();
	}

	const Math::Vector2& GameObject::GetPrevOffset() const
	{
		return m_TransformComponent->GetPrevOffset();
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
		if (m_StateController)
			m_StateController->Update();
	}

	void GameObject::PostUpdate(float dt, Camera* const curCamera)
	{
		assert(curCamera);

		TransformComponent* const cameraTransform = curCamera->GetComponent<TransformComponent*>("Transform");

		if (m_TransformComponent)
		{
			m_TransformComponent->AdjustByOffset();
			m_TransformComponent->TransformByCamera(dt, cameraTransform);
		}

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

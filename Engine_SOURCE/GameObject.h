#pragma once
#include "Common.h"
#include "Entity.h"
#include "CollisionFunc.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

namespace Game
{
	class GameObject : public Entity
	{
	public:
		GameObject(const std::string& name);
		GameObject(const GameObject& other);
		virtual ~GameObject() = 0;

	public:
		virtual GameObject* GetClone() const = 0;
		virtual void Update(float dt);
		virtual void PostUpdate(float dt, class Camera* const curCamera);
		virtual void Render(HDC dc);

		void SetMoveComponent(class MoveComponent* const moveComponent);
		void SetRigidBody(class RigidBody* const rigidBody);
		void SetStateController(class StateController* const stateController);
		void SetTransformComponent(class TransformComponent* const transformComponent);
		void SetRenderComponent(RenderComponent* const renderComponent);
		void AddCollider(class Collider* const collider);

		void SetTexture(const std::string& textureName) { m_RenderComponent->SetTexture(textureName); }
		void SetPos(const Math::Vector2& pos) { m_TransformComponent->SetPos(pos); }
		void SetSize(const Math::Vector2& size) { m_TransformComponent->SetSize(size); }
		void SetOffset(const Math::Vector2& offset) { m_TransformComponent->SetOffset(offset); }
		void SetSizeFromTexture() { SetSize(m_RenderComponent->GetTextureSize()); }

		const Math::Vector2& GetPos() const { return m_TransformComponent->GetPos(); }
		const Math::Vector2& GetFinalPos() const { return m_TransformComponent->GetFinalPos(); }
		const Math::Vector2& GetSize() const { return m_TransformComponent->GetSize(); }
		const Math::Vector2& GetOffset() const { return m_TransformComponent->GetOffset(); }
		const Math::Vector2& GetPrevOffset() const { return m_TransformComponent->GetPrevOffset(); }

		Gdiplus::Rect GetFinalRectInMYC() const { return m_TransformComponent->GetFinalRectInMYC(); }
		std::vector<Collider*>& GetColliders() { return m_VecColliders; }

		template <typename T>
		T GetComponent(const std::string& componentName) const;

	protected:
		std::map<std::string, Component*> m_MapComponents;
		std::vector<Collider*> m_VecColliders;
		class MoveComponent* m_MoveComponent;
		class RigidBody* m_RigidBody;
		class StateController* m_StateController;
		TransformComponent* m_TransformComponent;
		RenderComponent* m_RenderComponent;
	};
	template <typename T>
	T GameObject::GetComponent(const std::string& componentName) const
	{
		auto iter = m_MapComponents.find(componentName);
		if (iter == m_MapComponents.end())
			return nullptr;
		return dynamic_cast<T>(iter->second);
	}
}


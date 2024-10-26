#pragma once
#include "Common.h"
#include "Entity.h"
#include "CollisionFunc.h"

namespace Game
{
	class Component;
	class MoveComponent;
	class RigidBody;
	class TransformComponent;
	class StateController;
	class RenderComponent;
	class Camera;
	class Collider;
	class GameObject : public Entity
	{
	public:
		GameObject(const std::string& name);
		GameObject(const GameObject& other);
		virtual ~GameObject() = 0;

	public:
		virtual GameObject* GetClone() const = 0;
		virtual void Update(float dt);
		virtual void PostUpdate(float dt, Camera* const curCamera);
		virtual void Render(HDC dc);
		
		void SetMoveComponent(MoveComponent* const moveComponent);
		void SetRigidBody(RigidBody* const rigidBody);
		void SetStateController(StateController* const stateController);
		void SetTransformComponent(TransformComponent* const transformComponent);
		void SetRenderComponent(RenderComponent* const renderComponent);
		void AddCollider(Collider* const collider);

		void SetTexture(const std::string& textureName);
		void SetPos(const Math::Vector2& pos);
		void SetSize(const Math::Vector2& size);
		void SetOffset(const Math::Vector2& offset);
		void SetSizeFromTexture();

		const Math::Vector2& GetPos() const;
		const Math::Vector2& GetFinalPos() const;
		const Math::Vector2& GetSize() const;
		const Math::Vector2& GetOffset() const;
		const Math::Vector2& GetPrevOffset() const;

		Gdiplus::Rect GetFinalRectInMYC() const;
		std::vector<Collider*>& GetColliders() { return m_VecColliders; }

		template <typename T>
		T GetComponent(const std::string& componentName) const;

	protected:
		std::map<std::string, Component*> m_MapComponents;
		std::vector<Collider*> m_VecColliders;
		MoveComponent* m_MoveComponent;
		RigidBody* m_RigidBody;
		StateController* m_StateController;
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


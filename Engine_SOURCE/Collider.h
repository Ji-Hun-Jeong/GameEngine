#pragma once
#include "Component.h"
namespace Game
{
	class TransformComponent;
	class RenderComponent;
	class Player;
	class BackGround;
	class Collider : public Component, public CollisionFunc
	{
	public:
		Collider(GameObject* owner, UINT numOfCollider);
		~Collider();

	public:
		virtual void EnterCollisionDeliverOther(Collider* const otherCollider) = 0;
		virtual void OnCollisionDeliverOther(Collider* const otherCollider) = 0;
		virtual void ExitCollisionDeliverOther(Collider* const otherCollider) = 0;

		void Update(float dt, const TransformComponent* const ownerTransformComponent);
		void Render(HDC dc);

		const Math::Vector2& GetColliderPos() const;
		const Math::Vector2& GetColliderFinalPos() const;
		const Math::Vector2& GetColliderSize() const;

		uint32_t GetUniqueNumber() const { return m_ColliderUniqueNumber; }

	protected:
		Math::Vector2 m_colliderPos;
		Math::Vector2 m_colliderFinalPos;
		Math::Vector2 m_colliderSize;

		bool m_PermitRender;
		bool m_OnCollision;

		uint32_t m_ColliderUniqueNumber;
	};
}



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
		Collider(UINT numOfCollider);
		Collider(const Collider&) = default;
		virtual ~Collider();

	public:
		virtual Collider* GetClone() const = 0;
		virtual void EnterCollisionDeliverOther(Collider* const otherCollider) const = 0;
		virtual void OnCollisionDeliverOther(Collider* const otherCollider) const = 0;
		virtual void ExitCollisionDeliverOther(Collider* const otherCollider) const = 0;

		virtual void Update(float dt, const TransformComponent* const ownerTransformComponent);
		virtual void Render(HDC dc);


		const Math::Vector2& GetColliderPos() const;
		const Math::Vector2& GetColliderFinalPos() const;
		const Math::Vector2& GetColliderSize() const;

		uint32_t GetUniqueNumber() const { return m_ColliderUniqueNumber; }

	protected:
		Math::Vector2 m_colliderPos;
		Math::Vector2 m_colliderFinalPos;
		Math::Vector2 m_colliderSize;

		bool m_PermitRender;

		uint32_t m_ColliderUniqueNumber;
	};
}



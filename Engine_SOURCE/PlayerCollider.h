#pragma once
#include "Collider.h"
#include "CollisionFunc.h"
namespace Game
{
	class PlayerCollider : public Collider
	{
		COLLIDERDEFINE;
	public:
		PlayerCollider(GameObject* owner, UINT numOfCollider);
		~PlayerCollider();

	public:
		void EnterCollision(const BackGroundCollider* const collider) override;
		void OnCollision(const BackGroundCollider* const collider) override;
		void ExitCollision(const BackGroundCollider* const collider) override;

		void EnterCollision(const MonsterCollider* const collider) override;
		void OnCollision(const MonsterCollider* const collider) override;
		void ExitCollision(const MonsterCollider* const collider) override;


	};
}



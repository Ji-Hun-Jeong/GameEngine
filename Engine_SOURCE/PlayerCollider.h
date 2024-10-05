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
		void EnterCollision(BackGroundCollider* const collider) override;
		void OnCollision(BackGroundCollider* const collider) override;
		void ExitCollision(BackGroundCollider* const collider) override;

		void EnterCollision(MonsterCollider* const collider) override;
		void OnCollision(MonsterCollider* const collider) override;
		void ExitCollision(MonsterCollider* const collider) override;


	};
}



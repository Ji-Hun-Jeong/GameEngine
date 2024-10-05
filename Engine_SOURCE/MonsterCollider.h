#pragma once
#include "Collider.h"
namespace Game
{
	class MonsterCollider : public Collider
	{
		COLLIDERDEFINE;
	public:
		MonsterCollider(GameObject* owner, UINT numOfCollider);
		~MonsterCollider();

	public:
		void EnterCollision(PlayerCollider* const collider) override;
		void OnCollision(PlayerCollider* const collider) override;
		void ExitCollision(PlayerCollider* const collider) override;

	};
}



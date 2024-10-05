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
		void EnterCollision(const PlayerCollider* const collider) override;
		void OnCollision(const PlayerCollider* const collider) override;
		void ExitCollision(const PlayerCollider* const collider) override;

	};
}



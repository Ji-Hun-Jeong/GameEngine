#pragma once
#include "Collider.h"
namespace Game
{
	class MonsterCollider : public Collider
	{
		COLLIDERDEFINE;
		CLONE(Collider, MonsterCollider)
	public:
		MonsterCollider(UINT numOfCollider);
		MonsterCollider(const MonsterCollider&) = default;
		~MonsterCollider();

	public:
		void EnterCollision(const PlayerCollider* const collider) override;
		void OnCollision(const PlayerCollider* const collider) override;
		void ExitCollision(const PlayerCollider* const collider) override;

	};
}



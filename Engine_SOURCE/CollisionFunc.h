#pragma once
#include "Common.h"
namespace Game
{
	class PlayerCollider;
	class BackGroundCollider;
	class MonsterCollider;
	class CollisionFunc
	{
	public:
		virtual void EnterCollision(PlayerCollider* const collider);
		virtual void OnCollision(PlayerCollider* const collider);
		virtual void ExitCollision(PlayerCollider* const collider);

		virtual void EnterCollision(BackGroundCollider* const collider);
		virtual void OnCollision(BackGroundCollider* const collider);
		virtual void ExitCollision(BackGroundCollider* const collider);

		virtual void EnterCollision(MonsterCollider* const collider);
		virtual void OnCollision(MonsterCollider* const collider);
		virtual void ExitCollision(MonsterCollider* const collider);
	};
}



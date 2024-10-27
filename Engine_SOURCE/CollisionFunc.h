#pragma once
#include "Common.h"
namespace Game
{
	class CollisionFunc
	{
	public:
		virtual void EnterCollision(const class PlayerCollider* const collider);
		virtual void OnCollision(const class PlayerCollider* const collider);
		virtual void ExitCollision(const class PlayerCollider* const collider);

		virtual void EnterCollision(const class BackGroundCollider* const collider);
		virtual void OnCollision(const class BackGroundCollider* const collider);
		virtual void ExitCollision(const class BackGroundCollider* const collider);

		virtual void EnterCollision(const class MonsterCollider* const collider);
		virtual void OnCollision(const class MonsterCollider* const collider);
		virtual void ExitCollision(const class MonsterCollider* const collider);

	};
}



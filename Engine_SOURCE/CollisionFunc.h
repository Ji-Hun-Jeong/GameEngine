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
		virtual void EnterCollision(const PlayerCollider* const collider);
		virtual void OnCollision(const PlayerCollider* const collider);
		virtual void ExitCollision(const PlayerCollider* const collider);

		virtual void EnterCollision(const BackGroundCollider* const collider);
		virtual void OnCollision(const BackGroundCollider* const collider);
		virtual void ExitCollision(const BackGroundCollider* const collider);

		virtual void EnterCollision(const MonsterCollider* const collider);
		virtual void OnCollision(const MonsterCollider* const collider);
		virtual void ExitCollision(const MonsterCollider* const collider);

	};
}



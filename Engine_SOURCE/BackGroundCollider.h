#pragma once
#include "Collider.h"
namespace Game
{
	class BackGroundCollider : public Collider
	{
		COLLIDERDEFINE;
		CLONE(Collider, BackGroundCollider)
	public:
		BackGroundCollider(UINT numOfCollider);
		BackGroundCollider(const BackGroundCollider&) = default;
		~BackGroundCollider();

	public:
		void EnterCollision(const PlayerCollider* const collider) override;
		void OnCollision(const PlayerCollider* const collider) override;
		void ExitCollision(const PlayerCollider* const collider) override;

	};
}



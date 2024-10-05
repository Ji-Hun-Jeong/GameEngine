#pragma once
#include "Collider.h"
namespace Game
{
	class BackGroundCollider : public Collider
	{
		COLLIDERDEFINE;
	public:
		BackGroundCollider(GameObject* owner, UINT numOfCollider);
		~BackGroundCollider();

	public:
		void EnterCollision(const PlayerCollider* const collider) override;
		void OnCollision(const PlayerCollider* const collider) override;
		void ExitCollision(const PlayerCollider* const collider) override;

	};
}



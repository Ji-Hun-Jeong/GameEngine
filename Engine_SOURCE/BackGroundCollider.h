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
		void EnterCollision(PlayerCollider* const collider) override;
		void OnCollision(PlayerCollider* const collider) override;
		void ExitCollision(PlayerCollider* const collider) override;

	};
}



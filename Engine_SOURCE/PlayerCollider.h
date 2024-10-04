#pragma once
#include "Collider.h"
#include "CollisionFunc.h"
namespace Game
{
	class PlayerCollider : public Collider
	{
	public:
		PlayerCollider();
		~PlayerCollider();

	public:
		void EnterCollision(BackGround* const obj) override;
		void OnCollision(BackGround* const obj) override;
		void ExitCollision(BackGround* const obj) override;

		void EnterCollision(Monster* const obj) override;
		void OnCollision(Monster* const obj) override;
		void ExitCollision(Monster* const obj) override;
	};
}



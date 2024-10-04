#pragma once
#include "Collider.h"
namespace Game
{
	class BackGroundCollider : public Collider
	{
	public:
		BackGroundCollider();
		~BackGroundCollider();

	public:
		void EnterCollision(Player* const obj) override;
		void OnCollision(Player* const obj) override;
		void ExitCollision(Player* const obj) override;
	};
}



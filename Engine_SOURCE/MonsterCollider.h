#pragma once
#include "Collider.h"
namespace Game
{
	class MonsterCollider : public Collider
	{
	public:
		MonsterCollider();
		~MonsterCollider();

	public:
		void EnterCollision(Player* const obj) override;
		void OnCollision(Player* const obj) override;
		void ExitCollision(Player* const obj) override;
	};
}



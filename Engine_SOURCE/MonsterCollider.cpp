#include "MonsterCollider.h"

namespace Game
{
	MonsterCollider::MonsterCollider()
		: Collider()
	{
	}
	MonsterCollider::~MonsterCollider()
	{
	}
	void MonsterCollider::EnterCollision(Player* const obj)
	{
		cout << "Enter Monster -> Player\n";
	}
	void MonsterCollider::OnCollision(Player* const obj)
	{
		cout << "On Monster -> Player\n";
	}
	void MonsterCollider::ExitCollision(Player* const obj)
	{
		cout << "Exit Monster -> Player\n";
	}
}
#include "MonsterCollider.h"

namespace Game
{
	MonsterCollider::MonsterCollider(GameObject* owner, UINT numOfCollider)
		: Collider(owner, numOfCollider)
	{
	}
	MonsterCollider::~MonsterCollider()
	{
	}
	void MonsterCollider::EnterCollision(PlayerCollider* const collider)
	{
		cout << "Enter Monster -> PlayerCollider\n";
	}
	void MonsterCollider::OnCollision(PlayerCollider* const collider)
	{
		cout << "On Monster -> PlayerCollider\n";
	}
	void MonsterCollider::ExitCollision(PlayerCollider* const collider)
	{
		cout << "Exit Monster -> PlayerCollider\n";
	}
}
#include "MonsterCollider.h"

namespace Game
{
	MonsterCollider::MonsterCollider(UINT numOfCollider)
		: Collider(numOfCollider)
	{
	}
	MonsterCollider::~MonsterCollider()
	{
	}
	void MonsterCollider::EnterCollision(const PlayerCollider* const collider)
	{
		//cout << "Enter Monster <- PlayerCollider\n";
	}
	void MonsterCollider::OnCollision(const PlayerCollider* const collider)
	{
		//cout << "On Monster <- PlayerCollider\n";
	}
	void MonsterCollider::ExitCollision(const PlayerCollider* const collider)
	{
		//cout << "Exit Monster <- PlayerCollider\n";
	}
}
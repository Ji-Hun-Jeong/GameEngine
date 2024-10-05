#include "PlayerCollider.h"
#include "Player.h"
#include "BackGround.h"
#include "MonsterCollider.h"

namespace Game
{
	PlayerCollider::PlayerCollider(GameObject* owner, UINT numOfCollider)
		: Collider(owner, numOfCollider)
	{
	}
	PlayerCollider::~PlayerCollider()
	{
	}
	void PlayerCollider::EnterCollision(BackGroundCollider* const collider)
	{
		cout << "Enter Player -> BackGroundCollider\n";
	}
	void PlayerCollider::OnCollision(BackGroundCollider* const collider)
	{
		cout << "On Player -> BackGroundCollider\n";
	}
	void PlayerCollider::ExitCollision(BackGroundCollider* const collider)
	{
		cout << "Exit Player -> BackGroundCollider\n";
	}

	void PlayerCollider::EnterCollision(MonsterCollider* const collider)
	{
		cout << "Enter Player -> MonsterCollider\n";
	}
	void PlayerCollider::OnCollision(MonsterCollider* const collider)
	{
		cout << "On Player -> MonsterCollider\n";
	}
	void PlayerCollider::ExitCollision(MonsterCollider* const collider)
	{
		cout << "Exit Player -> MonsterCollider\n";
	}
}

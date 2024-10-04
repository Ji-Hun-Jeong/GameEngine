#include "PlayerCollider.h"
#include "Player.h"
#include "BackGround.h"

namespace Game
{
	PlayerCollider::PlayerCollider()
		: Collider()
	{
	}
	PlayerCollider::~PlayerCollider()
	{
	}
	void PlayerCollider::EnterCollision(BackGround* const obj)
	{
		cout << "Enter Player -> Back\n";
	}
	void PlayerCollider::OnCollision(BackGround* const obj)
	{
		cout << "On Player -> Back\n";
	}
	void PlayerCollider::ExitCollision(BackGround* const obj)
	{
		cout << "Exit Player -> Back\n";
	}

	void PlayerCollider::EnterCollision(Monster* const obj)
	{
		cout << "Enter Player -> Monster\n";
	}
	void PlayerCollider::OnCollision(Monster* const obj)
	{
		cout << "On Player -> Monster\n";
	}
	void PlayerCollider::ExitCollision(Monster* const obj)
	{
		cout << "Exit Player -> Monster\n";
	}
}

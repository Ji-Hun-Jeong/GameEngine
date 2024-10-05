#include "BackGroundCollider.h"

namespace Game
{
	BackGroundCollider::BackGroundCollider(GameObject* owner, UINT numOfCollider)
		: Collider(owner, numOfCollider)
	{
	}
	BackGroundCollider::~BackGroundCollider()
	{
	}
	void BackGroundCollider::EnterCollision(PlayerCollider* const collider)
	{
		cout << "Enter Back -> PlayerCollider\n";
	}
	void BackGroundCollider::OnCollision(PlayerCollider* const collider)
	{
		cout << "On Back -> PlayerCollider\n";
	}
	void BackGroundCollider::ExitCollision(PlayerCollider* const collider)
	{
		cout << "Exit Back -> PlayerCollider\n";
	}
}
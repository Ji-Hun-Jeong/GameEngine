#include "BackGroundCollider.h"

namespace Game
{
	BackGroundCollider::BackGroundCollider(UINT numOfCollider)
		: Collider(numOfCollider)
	{
	}
	BackGroundCollider::~BackGroundCollider()
	{
	}
	void BackGroundCollider::EnterCollision(const PlayerCollider* const collider)
	{
		cout << "Enter BackGroundCollider <- PlayerCollider\n";
	}
	void BackGroundCollider::OnCollision(const PlayerCollider* const collider)
	{
		cout << "On BackGroundCollider <- PlayerCollider\n";
	}
	void BackGroundCollider::ExitCollision(const PlayerCollider* const collider)
	{
		cout << "Exit BackGroundCollider <- PlayerCollider\n";
	}
}
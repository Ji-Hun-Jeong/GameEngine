#include "BackGroundCollider.h"

namespace Game
{
	BackGroundCollider::BackGroundCollider()
	{
	}
	BackGroundCollider::~BackGroundCollider()
	{
	}
	void BackGroundCollider::EnterCollision(Player* const obj)
	{
		cout << "Enter Back -> Player\n";
	}
	void BackGroundCollider::OnCollision(Player* const obj)
	{
		cout << "On Back -> Player\n";
	}
	void BackGroundCollider::ExitCollision(Player* const obj)
	{
		cout << "Exit Back -> Player\n";
	}
}
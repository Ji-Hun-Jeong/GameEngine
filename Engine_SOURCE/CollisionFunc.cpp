#include "CollisionFunc.h"

namespace Game
{
	void CollisionFunc::EnterCollision(PlayerCollider* const collider)
	{
		cout << "Basic Enter PlayerCollider!\n";
	}
	void CollisionFunc::OnCollision(PlayerCollider* const collider)
	{
		cout << "Basic On PlayerCollider!\n";
	}
	void CollisionFunc::ExitCollision(PlayerCollider* const collider)
	{
		cout << "Basic Exit PlayerCollider!\n";
	}
	void CollisionFunc::EnterCollision(BackGroundCollider* const collider)
	{
		cout << "Basic Enter BackGroundCollider\n";
	}
	void CollisionFunc::OnCollision(BackGroundCollider* const collider)
	{
		cout << "Basic On BackGroundCollider\n";
	}
	void CollisionFunc::ExitCollision(BackGroundCollider* const collider)
	{
		cout << "Basic Exit BackGroundCollider\n";
	}
	void CollisionFunc::EnterCollision(MonsterCollider* const collider)
	{
		cout << "Basic Enter MonsterCollider\n";
	}
	void CollisionFunc::OnCollision(MonsterCollider* const collider)
	{
		cout << "Basic On MonsterCollider\n";
	}
	void CollisionFunc::ExitCollision(MonsterCollider* const collider)
	{
		cout << "Basic Exit MonsterCollider\n";
	}
}
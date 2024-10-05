#include "CollisionFunc.h"

namespace Game
{
	void CollisionFunc::EnterCollision(const PlayerCollider* const collider)
	{
		cout << "Basic Enter PlayerCollider!\n";
	}
	void CollisionFunc::OnCollision(const PlayerCollider* const collider)
	{
		cout << "Basic On PlayerCollider!\n";
	}
	void CollisionFunc::ExitCollision(const PlayerCollider* const collider)
	{
		cout << "Basic Exit PlayerCollider!\n";
	}
	void CollisionFunc::EnterCollision(const BackGroundCollider* const collider)
	{
		cout << "Basic Enter BackGroundCollider\n";
	}
	void CollisionFunc::OnCollision(const BackGroundCollider* const collider)
	{
		cout << "Basic On BackGroundCollider\n";
	}
	void CollisionFunc::ExitCollision(const BackGroundCollider* const collider)
	{
		cout << "Basic Exit BackGroundCollider\n";
	}
	void CollisionFunc::EnterCollision(const MonsterCollider* const collider)
	{
		cout << "Basic Enter MonsterCollider\n";
	}
	void CollisionFunc::OnCollision(const MonsterCollider* const collider)
	{
		cout << "Basic On MonsterCollider\n";
	}
	void CollisionFunc::ExitCollision(const MonsterCollider* const collider)
	{
		cout << "Basic Exit MonsterCollider\n";
	}
}
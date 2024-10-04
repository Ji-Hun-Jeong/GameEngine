#include "Monster.h"
#include "Collider.h"
#include "BackGroundTransform.h"

namespace Game
{
	UINT Monster::s_numOfMonster = 0;
	Monster::Monster()
		: GameObject("Monster"+std::to_string(s_numOfMonster++))
	{
		SetTransformComponent(new BackGroundTransform(Math::Vector2(), Math::Vector2()));
	}
	Monster::~Monster()
	{
	}
	void Monster::EnterCollision(GameObject* obj)
	{
		obj->GetCollider()->EnterCollision(this);
	}
	void Monster::OnCollision(GameObject* obj)
	{
		obj->GetCollider()->OnCollision(this);
	}
	void Monster::ExitCollision(GameObject* obj)
	{
		obj->GetCollider()->ExitCollision(this);
	}
}

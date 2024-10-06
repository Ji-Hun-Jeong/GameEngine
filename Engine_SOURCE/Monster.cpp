#include "Monster.h"
#include "Collider.h"
#include "BackGroundTransform.h"

namespace Game
{
	UINT Monster::s_numOfMonster = 0;
	Monster::Monster()
		: GameObject("Monster"+std::to_string(s_numOfMonster++))
	{
		
	}
	Monster::~Monster()
	{
	}
}

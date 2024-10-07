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
	Monster::Monster(const Monster& other)
		: GameObject(other)
	{
		m_Name = "Monster" + std::to_string(s_numOfMonster);
		m_NameW = L"Monster" + std::to_wstring(s_numOfMonster++);
	}
	Monster::~Monster()
	{
	}
}

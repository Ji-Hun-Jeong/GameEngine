#pragma once
#include "GameObject.h"
namespace Game
{
	class Monster : public GameObject
	{
		CLONE(GameObject, Monster)
	public:
		Monster();
		Monster(const Monster& other);
		~Monster();

	private:
		static UINT s_numOfMonster;
	};
}



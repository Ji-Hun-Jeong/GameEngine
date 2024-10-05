#pragma once
#include "GameObject.h"
namespace Game
{
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster();

	private:
		static UINT s_numOfMonster;
	};
}



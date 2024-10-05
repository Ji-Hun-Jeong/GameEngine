#pragma once
#include "GameObject.h"
namespace Game
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

	private:
		static UINT s_numOfPlayer;
	};
}



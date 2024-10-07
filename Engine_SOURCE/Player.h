#pragma once
#include "GameObject.h"
namespace Game
{
	class Player : public GameObject
	{
		CLONE(GameObject, Player)
	public:
		Player();
		Player(const Player&) = default;
		~Player();

	private:
		static UINT s_numOfPlayer;
	};
}



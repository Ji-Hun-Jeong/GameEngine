#pragma once
#include "GameObject.h"
namespace Game
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

	public:
		void EnterCollision(GameObject* obj) override;
		void OnCollision(GameObject* obj) override;
		void ExitCollision(GameObject* obj) override;

	private:
		static UINT s_numOfPlayer;
	};
}



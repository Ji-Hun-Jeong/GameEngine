#pragma once
#include "GameObject.h"
namespace Game
{
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster();

	public:
		void EnterCollision(GameObject* obj) override;
		void OnCollision(GameObject* obj) override;
		void ExitCollision(GameObject* obj) override;

	private:
		static UINT s_numOfMonster;
	};
}



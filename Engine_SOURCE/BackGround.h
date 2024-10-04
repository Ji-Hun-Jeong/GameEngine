#pragma once
#include "GameObject.h"
namespace Game
{
	class BackGround : public GameObject
	{
	public:
		BackGround();
		~BackGround();

	public:
		void EnterCollision(GameObject* obj) override;
		void OnCollision(GameObject* obj) override;
		void ExitCollision(GameObject* obj) override;

	private:
		static UINT s_numOfBackGround;
	};
}



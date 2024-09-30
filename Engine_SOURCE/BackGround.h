#pragma once
#include "GameObject.h"
namespace Game
{
	class BackGround : public GameObject
	{
	public:
		BackGround();
		~BackGround();

	private:
		static UINT s_numOfBackGround;
	};
}



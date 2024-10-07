#pragma once
#include "GameObject.h"
namespace Game
{
	class BackGround : public GameObject
	{
		CLONE(GameObject, BackGround)
	public:
		BackGround();
		BackGround(const BackGround&) = default;
		~BackGround();

	private:
		static UINT s_numOfBackGround;
	};
}



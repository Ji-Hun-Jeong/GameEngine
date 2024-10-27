#include "BackGround.h"

namespace Game
{
	UINT BackGround::s_numOfBackGround = 0;
	BackGround::BackGround()
		: GameObject("BackGround"+std::to_string(s_numOfBackGround++))
	{
	}
	BackGround::~BackGround()
	{
	}
}

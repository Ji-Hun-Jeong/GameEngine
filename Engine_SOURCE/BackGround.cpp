#include "BackGround.h"
#include "BackGroundTransform.h"
#include "BackGroundRenderer.h"
#include "SceneMgr.h"

namespace Game
{
	UINT BackGround::s_numOfBackGround = 0;
	BackGround::BackGround()
		: GameObject("BackGround"+std::to_string(s_numOfBackGround++))
	{
		SetTransformComponent(new BackGroundTransform(Math::Vector2(), Math::Vector2()));
	}
	BackGround::~BackGround()
	{
	}
}

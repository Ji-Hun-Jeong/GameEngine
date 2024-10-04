#include "BackGround.h"
#include "BackGroundTransform.h"
#include "BackGroundRenderer.h"
#include "SceneMgr.h"
#include "Player.h"
#include "Collider.h"

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
	void BackGround::EnterCollision(GameObject* obj)
	{
		obj->GetCollider()->EnterCollision(this);
	}
	void BackGround::OnCollision(GameObject* obj)
	{
		obj->GetCollider()->OnCollision(this);
	}
	void BackGround::ExitCollision(GameObject* obj)
	{
		obj->GetCollider()->ExitCollision(this);
	}
}

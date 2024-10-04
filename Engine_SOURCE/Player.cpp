#include "Player.h"
#include "PlayerTransform.h"
#include "BasicRenderer.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "ResourceMgr.h"

namespace Game
{
	UINT Player::s_numOfPlayer = 0;
	Player::Player()
		: GameObject("Player"+std::to_string(s_numOfPlayer++))
	{
		SetTransformComponent(new PlayerTransform(Math::Vector2(), Math::Vector2()));
	}
	Player::~Player()
	{
		
	}
}
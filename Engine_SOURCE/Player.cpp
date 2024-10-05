#include "Player.h"
#include "PlayerTransform.h"
#include "BasicRenderer.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "ResourceMgr.h"
#include "BackGround.h"
#include "Collider.h"

namespace Game
{
	UINT Player::s_numOfPlayer = 0;
	Player::Player()
		: GameObject("Player"+std::to_string(s_numOfPlayer++))
	{
		SetTransformComponent(new PlayerTransform(this, Math::Vector2(), Math::Vector2()));
	}
	Player::~Player()
	{
		
	}
}
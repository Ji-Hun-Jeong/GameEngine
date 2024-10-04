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
		SetTransformComponent(new PlayerTransform(Math::Vector2(), Math::Vector2()));
	}
	Player::~Player()
	{
		
	}
	void Player::EnterCollision(GameObject* obj)
	{
		obj->GetCollider()->EnterCollision(this);
	}
	void Player::OnCollision(GameObject* obj)
	{
		obj->GetCollider()->OnCollision(this);
	}
	void Player::ExitCollision(GameObject* obj)
	{
		obj->GetCollider()->ExitCollision(this);
	}
}
#include "Player.h"
#include "PlayerTransform.h"
#include "BasicRenderer.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "ResourceMgr.h"

namespace Game
{
	Player::Player()
		: GameObject("Player")
	{
		m_TransformComponent = new PlayerTransform(this);
		Animator* animator = new Animator(this, 1.0f);
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 0, 127, 127, 127));
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 1, 127, 127, 127));
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 2, 127, 127, 127));
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 3, 127, 127, 127));
		animator->SetTexture("TestTexture");
		m_RenderComponent = animator;
	}
	Player::~Player()
	{
		if (m_TransformComponent)
			delete m_TransformComponent;
		if (m_RenderComponent)
			delete m_RenderComponent;
	}
}
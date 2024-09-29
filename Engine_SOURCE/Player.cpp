#include "Player.h"
#include "PlayerTransform.h"
#include "BasicRenderer.h"
#include "SpriteRenderer.h"

namespace Game
{
	Player::Player()
		: GameObject("Player")
	{
		m_TransformComponent = new PlayerTransform(this);
		m_RenderComponent = new SpriteRenderer(this);
	}
	Player::~Player()
	{
		if (m_TransformComponent)
			delete m_TransformComponent;
		if (m_RenderComponent)
			delete m_RenderComponent;
	}
}
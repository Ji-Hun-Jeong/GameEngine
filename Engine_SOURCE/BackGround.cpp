#include "BackGround.h"
#include "BackGroundTransform.h"
#include "BackGroundRenderer.h"
#include "SceneMgr.h"

namespace Game
{
	BackGround::BackGround()
		: GameObject("BackGround")
	{
		m_TransformComponent = new BackGroundTransform(this
			, Math::Vector2()
			, Math::Vector2(SceneMgr::GetInst().GetScreenWidth(), SceneMgr::GetInst().GetScreenHeight()));
		m_RenderComponent = new BackGroundRenderer(this);
		m_RenderComponent->SetTexture("BackGroundTexture");
	}
	BackGround::~BackGround()
	{
	}
}

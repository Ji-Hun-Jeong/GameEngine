#include "RectGenerator.h"
#include "MouseDragTransform.h"
#include "MouseRect.h"
#include "BasicRenderer.h"
#include "Camera.h"
#include "MouseMgr.h"

namespace Game
{
	RectGenerator::RectGenerator()
		: GameObject("RectGenerator")
		, m_CompleteMakeRect(false)
	{
		SetTransformComponent(new MouseDragTransform(Math::Vector2(), Math::Vector2()));
		SetMoveComponent(new MouseRect);
		SetRenderComponent(new BasicRenderer);
	}

	RectGenerator::~RectGenerator()
	{
	}
	void RectGenerator::Update(float dt)
	{
		GameObject::Update(dt);
	}
	void RectGenerator::PostUpdate(float dt, Camera* const curCamera)
	{
		GameObject::PostUpdate(dt, curCamera);
		m_CompleteMakeRect = MouseMgr::GetInst().IsReleased();
		if (m_CompleteMakeRect)
		{
			const Math::Vector2& cameraPos = curCamera->GetPos();
			const Math::Vector2& cameraSize = curCamera->GetSize();
			Gdiplus::Rect cameraScreen = Component::GetRectInMYC(cameraPos, cameraSize);

			const Math::Vector2& finalPos = m_TransformComponent->GetFinalPos();
			const Math::Vector2& size = m_TransformComponent->GetSize();
			m_DragedRect.X = static_cast<INT>(finalPos.x + cameraScreen.X);
			m_DragedRect.Y = static_cast<INT>(finalPos.y + cameraScreen.Y);
			m_DragedRect.Width = static_cast<INT>(size.x);
			m_DragedRect.Height = static_cast<INT>(size.y);
		}
	}
	void RectGenerator::Render(HDC dc)
	{
		GameObject::Render(dc);
	}
}

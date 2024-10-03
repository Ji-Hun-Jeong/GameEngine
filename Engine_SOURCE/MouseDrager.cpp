#include "MouseDrager.h"
#include "MouseDragTransform.h"
#include "BasicRenderer.h"
#include "Camera.h"

namespace Game
{
	MouseDrager::MouseDrager()
		: GameObject("MouseDrager")
		, m_CompleteMakeRect(false)
	{
		SetTransformComponent(new MouseDragTransform(this, Math::Vector2(), Math::Vector2()));
		SetRenderComponent(new BasicRenderer(this));
	}

	MouseDrager::~MouseDrager()
	{
	}
	void MouseDrager::Update(float dt)
	{
		GameObject::Update(dt);
	}
	void MouseDrager::PostUpdate(float dt, Camera* const curCamera)
	{
		GameObject::PostUpdate(dt, curCamera);
		MouseDragTransform* transform = static_cast<MouseDragTransform*>(m_TransformComponent);
		m_CompleteMakeRect = transform->IsReleased();
		if (m_CompleteMakeRect)
		{
			const Math::Vector2& cameraPos = curCamera->GetPos();
			const Math::Vector2& cameraSize = curCamera->GetSize();
			Gdiplus::Rect cameraScreen = Component::TransformMYC(cameraPos, cameraSize);

			const Math::Vector2& finalPos = m_TransformComponent->GetFinalPos();
			const Math::Vector2& size = m_TransformComponent->GetSize();
			m_DragedRect.X = static_cast<INT>(finalPos.x + cameraScreen.X);
			m_DragedRect.Y = static_cast<INT>(finalPos.y + cameraScreen.Y);
			m_DragedRect.Width = static_cast<INT>(size.x);
			m_DragedRect.Height = static_cast<INT>(size.y);
		}
	}
	void MouseDrager::Render(HDC dc)
	{
		GameObject::Render(dc);
	}
}

#include "MouseDrager.h"
#include "MouseDragTransform.h"
#include "BasicRenderer.h"

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
		MouseDragTransform* transform = static_cast<MouseDragTransform*>(m_TransformComponent);
		m_CompleteMakeRect = transform->IsReleased();
		if (m_CompleteMakeRect)
		{
			const Math::Vector2& pos = m_TransformComponent->GetPos();
			const Math::Vector2& size = m_TransformComponent->GetSize();
			m_DragedRect.X = static_cast<INT>(pos.x);
			m_DragedRect.Y = static_cast<INT>(pos.y);
			m_DragedRect.Width = static_cast<INT>(size.x);
			m_DragedRect.Height = static_cast<INT>(size.y);
		}
	}
	void MouseDrager::Render(HDC dc)
	{
		MouseDragTransform* transform = static_cast<MouseDragTransform*>(m_TransformComponent);
		if (transform->IsStartDraging())
		{
			GameObject::Render(dc);
		}
	}
}

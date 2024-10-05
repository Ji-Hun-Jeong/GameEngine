#include "Collider.h"
#include "BackGroundTransform.h"
#include "RenderComponent.h"
#include "BasicRenderer.h"
namespace Game
{
	Collider::Collider(GameObject* owner, UINT numOfCollider)
		: Component(owner, "Collider" + std::to_string(numOfCollider))
		, m_PermitRender(true)
		, m_ColliderUniqueNumber(0)
	{
		static uint32_t uniqueNumber = 0;
		m_ColliderUniqueNumber = uniqueNumber++;
	}
	Collider::~Collider()
	{
	}
	void Collider::Update(float dt, const TransformComponent* const ownerTransformComponent)
	{
		m_colliderPos = ownerTransformComponent->GetPos();
		m_colliderFinalPos = ownerTransformComponent->GetFinalPos();
		m_colliderSize = ownerTransformComponent->GetSize();
	}
	void Collider::Render(HDC dc)
	{
		if (m_PermitRender == false)
			return;
		Gdiplus::Graphics graphics(dc);
		Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 0), 1);
		Gdiplus::Rect finalRect;
		finalRect.X = static_cast<INT>(m_colliderFinalPos.x - m_colliderSize.x / 2.0f);
		finalRect.Y = static_cast<INT>(m_colliderFinalPos.y - m_colliderSize.y / 2.0f);
		finalRect.Width = static_cast<INT>(m_colliderSize.x);
		finalRect.Height = static_cast<INT>(m_colliderSize.y);
		int right = finalRect.X + finalRect.Width;
		int bottom = finalRect.Y + finalRect.Height;
		graphics.DrawRectangle(&pen, finalRect);
	}
	const Math::Vector2& Collider::GetColliderPos() const
	{
		return m_colliderPos;
	}
	const Math::Vector2& Collider::GetColliderFinalPos() const
	{
		return m_colliderFinalPos;
	}
	const Math::Vector2& Collider::GetColliderSize() const
	{
		return m_colliderSize;
	}
}

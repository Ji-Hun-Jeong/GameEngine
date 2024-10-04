#include "Collider.h"
#include "BackGroundTransform.h"
#include "RenderComponent.h"
#include "BasicRenderer.h"
namespace Game
{
	Collider::Collider()
		: Component("Collider")
		, m_TransformComponent(new BackGroundTransform(Math::Vector2(), Math::Vector2()))
		, m_RenderComponent(new BasicRenderer)
		, m_PermitRender(true)
		, m_OnCollision(false)
	{
	}
	Collider::~Collider()
	{
		delete m_TransformComponent;
		delete m_RenderComponent;
	}
	void Collider::Update(float dt, const TransformComponent* const ownerTransformComponent)
	{
		ownerTransformComponent->CopyValue(m_TransformComponent);
	}
	void Collider::Render(HDC dc)
	{
		if (m_PermitRender)
			m_RenderComponent->Render(dc, m_TransformComponent);
	}
	const Math::Vector2& Collider::GetColliderPos() const
	{
		return m_TransformComponent->GetPos();
	}
	const Math::Vector2& Collider::GetColliderFinalPos() const
	{
		return m_TransformComponent->GetFinalPos();
	}
	const Math::Vector2& Collider::GetColliderSize() const
	{
		return m_TransformComponent->GetSize();
	}
}

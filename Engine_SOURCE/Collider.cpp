#include "Collider.h"
#include "BackGroundTransform.h"
#include "RenderComponent.h"
namespace Game
{
	Collider::Collider(GameObject* const owner, TransformComponent* const transformComponent
		, RenderComponent* const renderComponent)
		: Component("Collider", owner)
		, m_TransformComponent(transformComponent)
		, m_RenderComponent(renderComponent)
		, m_PermitRender(true)
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
}

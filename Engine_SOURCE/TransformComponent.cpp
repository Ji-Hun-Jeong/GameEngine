#include "TransformComponent.h"
#include "Camera.h"

namespace Game
{
	TransformComponent::TransformComponent(const std::string& name, GameObject* const owner
		, const Math::Vector2& pos, const Math::Vector2& size)
		: Component(name, owner)
		, m_Pos(pos)
		, m_Size(size)
	{
	}
	TransformComponent::~TransformComponent()
	{
	}
	void TransformComponent::PostUpdate(float dt, const TransformComponent* const curCameraTransform)
	{
		const Math::Vector2& cameraPos = curCameraTransform->GetPos();
		const Math::Vector2& cameraSize = curCameraTransform->GetSize();
		RECT newRect = TransformMYC(cameraPos, cameraSize);
	
		m_FinalPos.x = m_Pos.x - newRect.left;
		m_FinalPos.y = m_Pos.y - newRect.top;
	}
}

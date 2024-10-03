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
	Gdiplus::Rect TransformComponent::GetFinalRectInMYC() const
	{
		return GetRectInMYC(m_FinalPos, m_Size);
	}
}

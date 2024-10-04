#include "TransformComponent.h"
#include "Camera.h"

namespace Game
{
	TransformComponent::TransformComponent(const std::string& name, const Math::Vector2& pos
		, const Math::Vector2& size)
		: Component(name)
		, m_Pos(pos)
		, m_Size(size)
	{
	}
	TransformComponent::TransformComponent(const TransformComponent& other)
		: Component(other)
		, m_Pos(other.m_Pos)
		, m_FinalPos(other.m_FinalPos)
		, m_Size(other.m_Size)
	{
	}
	TransformComponent::~TransformComponent()
	{
	}
	void TransformComponent::CopyValue(TransformComponent* const other) const
	{
		other->m_Pos = m_Pos;
		other->m_FinalPos = m_FinalPos;
		other->m_Size = m_Size;
	}
	Gdiplus::Rect TransformComponent::GetFinalRectInMYC() const
	{
		return GetRectInMYC(m_FinalPos, m_Size);
	}
}

#include "TransformComponent.h"

namespace Game
{
	TransformComponent::TransformComponent()
		: TransformComponent(Math::Vector2(), Math::Vector2())
	{

	}
	TransformComponent::TransformComponent(const Math::Vector2& pos, const Math::Vector2& size)
		: Component("Transform")
		, m_Pos(pos)
		, m_Size(size)
	{
	}
	TransformComponent::~TransformComponent()
	{
	}
	void TransformComponent::AdjustByOffset()
	{
		m_FinalPos = m_Offset;
	}
	void TransformComponent::CopyValue(TransformComponent* const other) const
	{
		other->m_Pos = m_Pos;
		other->m_FinalPos = m_FinalPos;
		other->m_Offset = m_Offset;
		other->m_Size = m_Size;
	}
	Gdiplus::Rect TransformComponent::GetFinalRectInMYC() const
	{
		return GetRectInMYC(m_FinalPos, m_Size);
	}
}

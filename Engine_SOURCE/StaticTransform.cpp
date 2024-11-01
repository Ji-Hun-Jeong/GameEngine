#include "StaticTransform.h"

namespace Game
{
	StaticTransform::StaticTransform()
		: StaticTransform(Math::Vector2(), Math::Vector2())
	{

	}
	StaticTransform::StaticTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(pos, size)
	{
	}
	StaticTransform::~StaticTransform()
	{
	}
	void StaticTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		m_FinalPos += m_Pos;
	}
}

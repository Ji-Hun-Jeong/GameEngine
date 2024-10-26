#include "MouseDragTransform.h"
#include "MouseMgr.h"

namespace Game
{
	MouseDragTransform::MouseDragTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(pos, size)
	{
	}
	MouseDragTransform::~MouseDragTransform()
	{
	}
	void MouseDragTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		m_FinalPos += m_Pos;
	}
}
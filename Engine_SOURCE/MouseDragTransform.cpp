#include "MouseDragTransform.h"
#include "MouseMgr.h"

namespace Game
{
	MouseDragTransform::MouseDragTransform(GameObject* owner
		, const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(owner, pos, size)
	{
	}
	MouseDragTransform::~MouseDragTransform()
	{
	}
	void MouseDragTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		m_FinalPos = m_Pos;
	}
}
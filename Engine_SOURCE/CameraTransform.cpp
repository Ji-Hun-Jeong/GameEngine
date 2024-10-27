#include "CameraTransform.h"

namespace Game
{
	CameraTransform::CameraTransform()
		: CameraTransform(Math::Vector2(), Math::Vector2())
	{

	}
	CameraTransform::CameraTransform(const Math::Vector2& pos, const Math::Vector2& size)
		: TransformComponent(pos, size)
	{
	}
	CameraTransform::~CameraTransform()
	{
	}
	void CameraTransform::TransformByCamera(float dt, const TransformComponent* const curCameraTransform)
	{
		m_FinalPos += m_Pos;
	}
}

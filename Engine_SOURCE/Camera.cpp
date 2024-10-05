#include "Camera.h"
#include "CameraTransform.h"

namespace Game
{
	UINT Camera::s_numOfCamera = 0;
	Camera::Camera()
		: GameObject("Camera" + std::to_string(s_numOfCamera++))
	{
		SetTransformComponent(new CameraTransform(this, Math::Vector2(640.0f, 360.0f)
			, Math::Vector2(1280, 720)));
	}
	Camera::~Camera()
	{
	}

}
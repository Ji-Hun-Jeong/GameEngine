#include "Camera.h"
#include "CameraTransform.h"

namespace Game
{
	UINT Camera::s_numOfCamera = 0;
	Camera::Camera()
		: GameObject("Camera" + std::to_string(s_numOfCamera++))
	{

	}
	Camera::~Camera()
	{
	}

}
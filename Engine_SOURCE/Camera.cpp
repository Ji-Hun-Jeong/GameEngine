#include "Camera.h"
#include "CameraTransform.h"

namespace Game
{
	UINT Camera::s_numOfCamera = 0;
	Camera::Camera()
		: GameObject("Camera" + std::to_string(s_numOfCamera++))
	{
		m_TransformComponent = new CameraTransform(this, Math::Vector2(), Math::Vector2(1280, 720));
	}
	Camera::~Camera()
	{
	}
	void Camera::Update(float dt)
	{
		GameObject::Update(dt);
	}
	void Camera::PostUpdate(float dt, Camera* const curCamera)
	{

	}
	void Camera::Render(HDC dc)
	{

	}
}
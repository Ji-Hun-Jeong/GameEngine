#include "CameraFactory.h"
#include "Camera.h"
#include "CameraMove.h"
#include "CameraTransform.h"

namespace Game
{
	GameObject* CameraFactory::CreateObject(const Math::Vector2& pos, const Math::Vector2& size)
	{
		Camera* camera = new Camera;

		CameraTransform* cameraTransform = new CameraTransform(Math::Vector2(), Math::Vector2());

		camera->SetTransformComponent(cameraTransform);

		camera->SetPos(pos);
		camera->SetSize(size);

		MoveComponent* move = new CameraMove;
		camera->SetMoveComponent(move);
		return camera;
	}
}
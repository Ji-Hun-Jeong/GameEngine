#pragma once
#include "GameObject.h"
namespace Game
{
	class Camera : public GameObject
	{
		CLONE(GameObject, Camera)
	public:
		Camera();
		Camera(const Camera&) = default;
		~Camera();

	private:
		static UINT s_numOfCamera;
	};
}



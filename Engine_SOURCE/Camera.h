#pragma once
#include "GameObject.h"
namespace Game
{
	class Camera : public GameObject
	{
	public:
		Camera();
		~Camera();

	private:
		static UINT s_numOfCamera;
	};
}



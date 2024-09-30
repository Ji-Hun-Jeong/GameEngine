#pragma once
#include "GameObject.h"
namespace Game
{
	class Camera : public GameObject
	{
	public:
		Camera();
		~Camera();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera) override;
		void Render(HDC dc) override;

	private:
		static UINT s_numOfCamera;
	};
}



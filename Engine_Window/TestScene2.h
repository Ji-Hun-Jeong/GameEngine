#pragma once
#include "Scene.h"
namespace Game
{
	class TestScene2 : public Scene
	{
	public:
		explicit TestScene2(UINT width, UINT height);
		~TestScene2();

	public:
		void EnterScene() override;
		void ExitScene() override;
		void DetectSceneEvent() override;

	private:

	};

}


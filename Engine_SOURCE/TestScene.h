#pragma once
#include "Scene.h"
namespace Game
{
	class TestScene : public Scene
	{
	public:
		explicit TestScene(UINT width, UINT height);
		~TestScene();

	public:
		void EnterScene() override;
		void ExitScene() override;
		void DetectSceneEvent() override;

	private:

	};
}


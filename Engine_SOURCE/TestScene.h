#pragma once
#include "Scene.h"
namespace Game
{
	class TestScene : public Scene
	{
	public:
		TestScene();
		~TestScene();

	public:
		void EnterScene() override;
		void ExitScene() override;
		void DetectSceneEvent() override;

	private:

	};
}


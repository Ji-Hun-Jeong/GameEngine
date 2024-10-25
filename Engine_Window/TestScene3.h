#pragma once
#include "Scene.h"
namespace Game
{
	class TestScene3 : public Scene
	{
	public:
		explicit TestScene3(UINT width, UINT height);
		TestScene3(const TestScene3&) = delete;
		~TestScene3();

	public:
		void EnterScene() override;
		void ExitScene() override;
		void DetectSceneEvent() override;
	};
}



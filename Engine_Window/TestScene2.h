#pragma once
#include "Scene.h"
#include "AnimationGenerator.h"
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
		void Update(float dt) override;
		void PostUpdate(float dt) override;
		void Render(HDC dc) override;

	private:

	};

}


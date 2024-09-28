#include "TestScene.h"
#include "Player.h"

namespace Game
{
	TestScene::TestScene()
		: Scene("Test")
	{
		GameObject* obj = new Player;

		AddGameObject(obj);
	}
	TestScene::~TestScene()
	{
	}
}

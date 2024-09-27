#include "TestScene.h"
#include "PlayerKeyMove.h"
#include "Player.h"

namespace Game
{
	TestScene::TestScene()
		: Scene("Test")
	{
		GameObject* obj = new Player;
		obj->AddComponent(new PlayerKeyMove);
		AddGameObject(obj);
	}
	TestScene::~TestScene()
	{
	}
}

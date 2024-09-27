#include "TestScene.h"
#include "MouseEventReceiver.h"
#include "KeyEventReceiver.h"

namespace Game
{
	TestScene::TestScene()
		: Scene("Test")
	{
		GameObject* obj = new GameObject("obj");
		obj->AddComponent(new MouseEventReceiver);
		obj->AddComponent(new KeyEventReceiver);
		AddGameObject(obj);
	}
	TestScene::~TestScene()
	{
		std::cout << "TestScene Destructor!\n";
	}
}

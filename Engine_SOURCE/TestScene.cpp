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
	void TestScene::EnterScene()
	{
	}
	void TestScene::ExitScene()
	{
	}
	void TestScene::DetectSceneEvent()
	{
		if (KeyMgr::GetInst().GetKeyState(eKeyType::B1, eButtonState::Tap))
			SceneMgr::GetInst().RequestChangeScene("Test2");
	}
}

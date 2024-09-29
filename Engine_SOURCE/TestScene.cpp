#include "TestScene.h"
#include "Player.h"


namespace Game
{
	TestScene::TestScene(UINT width, UINT height)
		: Scene("Test", width, height)
	{
		GameObject* obj = new Player;

		AddGameObject(obj);
	}
	TestScene::~TestScene()
	{
	}
	void TestScene::EnterScene()
	{
		std::cout << m_Name + "Enter\n";
	}
	void TestScene::ExitScene()
	{
		std::cout << m_Name + "Exit\n";
	}
	void TestScene::DetectSceneEvent()
	{
		if (KeyMgr::GetInst().GetKeyState(eKeyType::B1, eButtonState::Tap))
			SceneMgr::GetInst().RequestChangeScene("Test2");
	}
}

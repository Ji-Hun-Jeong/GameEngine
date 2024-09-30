#include "TestScene.h"
#include "BackGround.h"
#include "Camera.h"
#include "Player.h"

namespace Game
{
	TestScene::TestScene(UINT width, UINT height)
		: Scene("Test", width, height)
	{
		AddGameObject(new Player);
		AddGameObject(new BackGround);
		
		AddCamera(new Camera);
		SetCurCamera("Camera0");
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

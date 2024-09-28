#include "TestScene2.h"

namespace Game
{
	TestScene2::TestScene2()
		: Scene("Test2")
	{
	}

	TestScene2::~TestScene2()
	{
	}

	void TestScene2::EnterScene()
	{
	}

	void TestScene2::ExitScene()
	{
	}

	void TestScene2::DetectSceneEvent()
	{
		if (KeyMgr::GetInst().GetKeyState(eKeyType::B1, eButtonState::Tap))
			SceneMgr::GetInst().RequestChangeScene("Test");
	}
}


#include "TestScene2.h"

namespace Game
{
	TestScene2::TestScene2(UINT width, UINT height)
		: Scene("Test2", width, height)
	{
	}

	TestScene2::~TestScene2()
	{
	}

	void TestScene2::EnterScene()
	{
		std::cout << m_Name + "Enter\n";
	}

	void TestScene2::ExitScene()
	{
		std::cout << m_Name + "Exit\n";
	}

	void TestScene2::DetectSceneEvent()
	{
		if (KeyMgr::GetInst().GetKeyState(eKeyType::B1, eButtonState::Tap))
			SceneMgr::GetInst().RequestChangeScene("Test");
	}
}


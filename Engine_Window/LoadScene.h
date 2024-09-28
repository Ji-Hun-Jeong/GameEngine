#pragma once
#include "SceneMgr.h"
#include "TestScene.h"
#include "TestScene2.h"

namespace Game
{
	void LoadScene()
	{
		SceneMgr& inst = SceneMgr::GetInst();
		inst.AddScene(new TestScene);
		inst.AddScene(new TestScene2);

		inst.SetFirstScene("Test");
	}
}
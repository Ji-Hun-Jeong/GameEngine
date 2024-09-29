#pragma once
#include "SceneMgr.h"
#include "TestScene.h"
#include "TestScene2.h"
#include "Application.h"

namespace Game
{
	void LoadScene()
	{
		SceneMgr& inst = SceneMgr::GetInst();
		UINT screenWidth = inst.GetScreenWidth();
		UINT screenHeight= inst.GetScreenHeight();
		inst.AddScene(new TestScene(screenWidth, screenHeight));
		inst.AddScene(new TestScene2(screenWidth, screenHeight));

		inst.SetFirstScene("Test");
	}
}
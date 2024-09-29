#pragma once
#include "SceneMgr.h"
#include "TestScene.h"
#include "TestScene2.h"
#include "Application.h"
#include "ResourceMgr.h"

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
	void LoadResource()
	{
		ResourceMgr& inst = ResourceMgr::GetInst();
		inst.LoadResource(eResourceType::Texture, "TestTexture", "Texture/char_black.bmp");
	}
}
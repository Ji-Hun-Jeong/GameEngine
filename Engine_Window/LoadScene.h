#pragma once
#include "SceneMgr.h"
#include "TestScene.h"
#include "TestScene2.h"
#include "TestScene3.h"
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
		inst.AddScene(new TestScene3(screenWidth, screenHeight));

		inst.SetFirstScene("Test3");
	}
	void LoadResource()
	{
		ResourceMgr& inst = ResourceMgr::GetInst();
		inst.LoadResource(eResourceType::Texture, "PlayerTexture", "Texture/char_black.bmp");
		inst.LoadResource(eResourceType::Texture, "BackGroundTexture", "Texture/char_black.bmp");
	}
}
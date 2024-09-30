#include "TestScene.h"
#include "Animator.h"
#include "BackGroundRenderer.h"

namespace Game
{
	TestScene::TestScene(UINT width, UINT height)
		: Scene("Test", width, height)
	{
		// 생성자에 SetTexture있음
		GameObject* player = new Player;
		player->SetSize(Math::Vector2(100.0f, 100.0f));
		Animator* animator = new Animator(player, 1.0f);
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 0, 127, 127, 127));
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 1, 127, 127, 127));
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 2, 127, 127, 127));
		animator->AddTextureCutInfo(Gdiplus::Rect(127 * 3, 127, 127, 127));
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");
		AddGameObject(eLayerType::Player, player);

		GameObject* backGround = new BackGround;
		backGround->SetRenderComponent(new BackGroundRenderer(backGround));
		backGround->SetTexture("BackGroundTexture");
		backGround->SetSizeFromTexture();
		AddGameObject(eLayerType::BackGround, backGround);

		Camera* camera = new Camera;
		camera->SetPos(Math::Vector2(640.0f, 360.0f));
		AddCamera(camera);
		SetCurCamera(camera);
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
	void TestScene::Update(float dt)
	{
		Scene::Update(dt);
	}
	void TestScene::PostUpdate(float dt)
	{
		Scene::PostUpdate(dt);
	}
	void TestScene::Render(HDC dc)
	{
		Scene::Render(dc);
	}
}

#include "TestScene.h"
#include "Animator.h"
#include "BackGroundRenderer.h"

namespace Game
{
	TestScene::TestScene(UINT width, UINT height)
		: Scene("Test", width, height)
	{
		// �����ڿ� SetTexture����
		GameObject* player = new Player;
		player->SetPos(Math::Vector2(50.0f, 50.0f));
		player->SetSize(Math::Vector2(100.0f, 100.0f));

		Animator* animator = new Animator(player, 0.3f);
		animator->AddTextureCutInfoByFile("Animation/PlayerWalk.txt");
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");
		AddGameObject(eLayerType::Player, player);
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		player = new Player;
		player->SetPos(Math::Vector2(100.0f, 100.0f));
		player->SetSize(Math::Vector2(100.0f, 100.0f));

		animator = new Animator(player, 0.1f);
		animator->AddTextureCutInfoByFile("Animation/PlayerRun.txt");
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");
		AddGameObject(eLayerType::Player, player);
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		player = new Player;
		player->SetPos(Math::Vector2(150.0f, 150.0f));
		player->SetSize(Math::Vector2(100.0f, 100.0f));

		animator = new Animator(player, 0.3f);
		animator->AddTextureCutInfoByFile("Animation/PlayerDead.txt");
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");
		AddGameObject(eLayerType::Player, player);
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		player = new Player;
		player->SetPos(Math::Vector2(200.0f, 200.0f));
		player->SetSize(Math::Vector2(100.0f, 100.0f));

		animator = new Animator(player, 0.3f);
		animator->AddTextureCutInfoByFile("Animation/PlayerIdle1.txt");
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");
		AddGameObject(eLayerType::Player, player);
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		player = new Player;
		player->SetPos(Math::Vector2(250.0f, 250.0f));
		player->SetSize(Math::Vector2(100.0f, 100.0f));

		animator = new Animator(player, 0.3f);
		animator->AddTextureCutInfoByFile("Animation/PlayerIdle2.txt");
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");
		AddGameObject(eLayerType::Player, player);
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		GameObject* backGround = new BackGround;
		backGround->SetRenderComponent(new BackGroundRenderer(backGround));
		backGround->SetTexture("BackGroundTexture");
		backGround->SetPos(Math::Vector2(1024.0f, 1024.0f));
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

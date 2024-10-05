#include "TestScene.h"
#include "Animator.h"
#include "BackGroundRenderer.h"
#include "PlayerCollider.h"
#include "BackGroundCollider.h"
#include "BackGroundTransform.h"
#include "BasicRenderer.h"
#include "CollisionMgr.h"
#include "Monster.h"
#include "MonsterCollider.h"

namespace Game
{
	TestScene::TestScene(UINT width, UINT height)
		: Scene("Test", width, height)
	{
		// 생성자에 SetTexture있음
		GameObject* player = new Player;
		player->SetPos(Math::Vector2(-51.0f, -51.0f));
		player->SetSize(Math::Vector2(100.0f, 100.0f));

		Animator* animator = new Animator(player, 0.1f);
		animator->AddTextureCutInfoByFile("Animation/PlayerWalk.txt");
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");

		Collider* collider = new PlayerCollider(player, 0);
		player->AddCollider(collider);
		AddGameObject(eLayerType::Player, player);

		GameObject* monster = new Monster;
		monster->SetPos(Math::Vector2(50.0f, 50.0f));
		monster->SetSize(Math::Vector2(100.0f, 100.0f));

		animator = new Animator(monster, 0.1f);
		animator->AddTextureCutInfoByFile("Animation/PlayerRun.txt");
		monster->SetRenderComponent(animator);
		monster->SetTexture("PlayerTexture");

		collider = new MonsterCollider(monster,0);
		monster->AddCollider(collider);
		AddGameObject(eLayerType::Monster, monster);

		GameObject* backGround = new BackGround;
		backGround->SetRenderComponent(new BackGroundRenderer(backGround));
		backGround->SetTexture("BackGroundTexture");
		backGround->SetPos(Math::Vector2(1024.0f, 1024.0f));
		backGround->SetSizeFromTexture();

		collider = new BackGroundCollider(backGround, 0);
		backGround->AddCollider(collider);
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
		CollisionMgr::GetInst().CheckInCollisionMatrix(eLayerType::Monster, eLayerType::Player, true);
		CollisionMgr::GetInst().CheckInCollisionMatrix(eLayerType::BackGround, eLayerType::Player, true);
		std::cout << m_Name + "Enter\n";
	}
	void TestScene::ExitScene()
	{
		CollisionMgr::GetInst().CheckInCollisionMatrix(eLayerType::Monster, eLayerType::Player, false);
		CollisionMgr::GetInst().CheckInCollisionMatrix(eLayerType::BackGround, eLayerType::Player, false);
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

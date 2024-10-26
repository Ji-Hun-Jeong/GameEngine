#include "TestScene.h"
#include "BackGroundRenderer.h"
#include "BackGroundCollider.h"
#include "BackGroundTransform.h"
#include "BasicRenderer.h"
#include "CollisionMgr.h"
#include "BasicRigidBody.h"
#include "PlayerFactory.h"
#include "MonsterFactory.h"
#include "CameraFactory.h"
#include "Monster.h"
#include "Player.h"

namespace Game
{
	TestScene::TestScene(UINT width, UINT height)
		: Scene("Test", width, height)
	{
		// 생성자에 SetTexture있음
		std::unique_ptr<Factory> factory = std::make_unique<PlayerFactory>();

		AddGameObject(eLayerType::Player, factory->CreateObject(new Player,
			Math::Vector2(640.0f, 360.0f), Math::Vector2(100.0f, 100.0f)));
		
		factory = std::make_unique<MonsterFactory>();

		AddGameObject(eLayerType::Monster, factory->CreateObject(new Monster,
			Math::Vector2(640.0f, 460.0f), Math::Vector2(100.0f, 100.0f)));
		AddGameObject(eLayerType::Monster, factory->CreateObject(new Monster,
			Math::Vector2(740.0f, 460.0f), Math::Vector2(100.0f, 100.0f)));

		GameObject* backGround = new BackGround;
		backGround->SetRenderComponent(new BackGroundRenderer);
		backGround->SetTexture("BackGroundTexture");
		backGround->SetPos(Math::Vector2(1024.0f, 1024.0f));
		backGround->SetSizeFromTexture();

		//collider = new BackGroundCollider(backGround, 0);
		//backGround->AddCollider(collider);
		AddGameObject(eLayerType::BackGround, backGround);

		
		factory = std::make_unique<CameraFactory>();
		Camera* camera = static_cast<Camera*>(factory->CreateObject(new Camera,
			Math::Vector2(640.0f, 360.0f), Math::Vector2(1280.0f, 720.0f)));
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

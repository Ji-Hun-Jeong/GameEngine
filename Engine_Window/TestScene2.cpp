#include "TestScene2.h"
#include "BackGroundRenderer.h"
#include "MouseDrager.h"
#include "AnimationGenerator.h"
#include "CollisionMgr.h"
#include "MouseDrag.h"
#include "MouseDragTransform.h"
#include "CameraFactory.h"

namespace Game
{
	TestScene2::TestScene2(UINT width, UINT height)
		: Scene("Test2", width, height)
	{
		GameObject* obj = new BackGround;
		obj->SetRenderComponent(new BackGroundRenderer);
		obj->SetTexture("BackGroundTexture");
		obj->SetSizeFromTexture();
		obj->SetPos(Math::Vector2(Math::Vector2(1024.0f, 1024.0f)));
		AddGameObject(eLayerType::BackGround, obj);
		
		obj = new AnimationGenerator;
		obj->SetTransformComponent(new MouseDragTransform(Math::Vector2(), Math::Vector2()));
		obj->SetMoveComponent(new MouseDrag);
		AddGameObject(eLayerType::Entity, obj);

		std::unique_ptr<Factory> factory = std::make_unique<CameraFactory>();
		Camera* camera = static_cast<Camera*>(factory->CreateObject(
			Math::Vector2(640.0f, 360.0f), Math::Vector2(1280.0f, 720.0f)));
		AddCamera(camera);
		SetCurCamera(camera);

	}

	TestScene2::~TestScene2()
	{
	}

	void TestScene2::EnterScene()
	{
		std::cout << m_Name + "Enter\n";
		CollisionMgr::GetInst().CheckInCollisionMatrix(eLayerType::Player, eLayerType::Monster, true);
	}

	void TestScene2::ExitScene()
	{
		std::cout << m_Name + "Exit\n";
		CollisionMgr::GetInst().CheckInCollisionMatrix(eLayerType::Player, eLayerType::Monster, false);
	}

	void TestScene2::DetectSceneEvent()
	{
		if (KeyMgr::GetInst().GetKeyState(eKeyType::B1, eButtonState::Tap))
			SceneMgr::GetInst().RequestChangeScene("Test");
	}
	void TestScene2::Update(float dt)
	{
		Scene::Update(dt);
	}
	void TestScene2::PostUpdate(float dt)
	{
		Scene::PostUpdate(dt);
	}
	void TestScene2::Render(HDC dc)
	{
		Scene::Render(dc);
	}
}


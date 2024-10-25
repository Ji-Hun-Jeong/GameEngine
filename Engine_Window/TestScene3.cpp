#include "TestScene3.h"
#include "UI.h"
#include "UIFactory.h"
#include "CameraFactory.h"

namespace Game
{
	TestScene3::TestScene3(UINT width, UINT height)
		: Scene("Test3", width, height)
	{
		std::unique_ptr<Factory> factory = std::make_unique<UIFactory>();
		
		UI* mainUI = static_cast<UI*>(
			factory->CreateObject(Math::Vector2(300.0f, 300.0f), Math::Vector2(900.0f, 700.0f)));

		AddGameObject(eLayerType::UI, mainUI);

		UI* childUI = static_cast<UI*>(factory->CreateObject());
		childUI->SetSize(Math::Vector2(500.0f, 500.0f));
		childUI->SetOffset(Math::Vector2(0.0f, 0.0f));
		mainUI->AddChildUI(childUI);

		childUI = static_cast<UI*>(factory->CreateObject());
		childUI->SetSize(Math::Vector2(100.0f, 100.0f));
		childUI->SetOffset(Math::Vector2(0.0f, 100.0f));
		mainUI->AddChildUI(childUI);

		factory = std::make_unique<CameraFactory>();
		Camera* camera = static_cast<Camera*>(factory->CreateObject(
			Math::Vector2(640.0f, 360.0f), Math::Vector2(1280.0f, 720.0f)));
		AddCamera(camera);
		SetCurCamera(camera);
	}
	TestScene3::~TestScene3()
	{

	}
	void TestScene3::EnterScene()
	{
		std::cout << m_Name + "Enter\n";
	}
	void TestScene3::ExitScene()
	{
		std::cout << m_Name + "Exit\n";
	}
	void TestScene3::DetectSceneEvent()
	{

	}
}
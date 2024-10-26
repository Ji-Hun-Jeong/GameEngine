#include "TestScene3.h"
#include "UI.h"
#include "UIFactory.h"
#include "CameraFactory.h"
#include "MainUI.h"
#include "DragUI.h"
#include "MouseUIMove.h"

namespace Game
{
	TestScene3::TestScene3(UINT width, UINT height)
		: Scene("Test3", width, height)
	{
		std::unique_ptr<Factory> factory = std::make_unique<UIFactory>();
		
		UI* mainUI = static_cast<UI*>(factory->CreateObject(new MainUI
			, Math::Vector2(600.0f, 300.0f), Math::Vector2(700.0f, 600.0f)));

		AddGameObject(eLayerType::UI, mainUI);

		UI* childUI = static_cast<UI*>(factory->CreateObject(new MainUI));
		childUI->SetSize(Math::Vector2(200.0f, 300.0f));
		childUI->SetOffset(Math::Vector2(-100.0f, -100.0f));
		mainUI->AddChildUI(childUI);

		UI* cchildUI = static_cast<UI*>(factory->CreateObject(new DragUI));
		cchildUI->SetMoveComponent(new MouseUIMove);
		cchildUI->SetSize(Math::Vector2(200.0f, 50.0f));
		cchildUI->SetOffset(Math::Vector2(0.0f, -125.0f));
		childUI->AddChildUI(cchildUI);

		/*childUI = static_cast<UI*>(factory->CreateObject(new MainUI));
		childUI->SetSize(Math::Vector2(200.0f, 300.0f));
		childUI->SetOffset(Math::Vector2(100.0f, 100.0f));
		mainUI->AddChildUI(childUI);

		cchildUI = static_cast<UI*>(factory->CreateObject(new DragUI));
		cchildUI->SetMoveComponent(new MouseUIMove);
		cchildUI->SetSize(Math::Vector2(200.0f, 50.0f));
		cchildUI->SetOffset(Math::Vector2(0.0f, -125.0f));
		childUI->AddChildUI(cchildUI);*/

		factory = std::make_unique<CameraFactory>();
		Camera* camera = static_cast<Camera*>(factory->CreateObject(new Camera,
			Math::Vector2(0.0f, 0.0f), Math::Vector2(1280.0f, 720.0f)));
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
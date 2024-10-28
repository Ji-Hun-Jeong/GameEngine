#include "TestScene3.h"
#include "UI.h"
#include "UIFactory.h"
#include "CameraFactory.h"
#include "MouseUIMove.h"
#include "FlowLayout.h"
#include "ChangeSceneEvent.h"
#include "UI.h"

namespace Game
{
	TestScene3::TestScene3(UINT width, UINT height)
		: Scene("Test3", width, height)
	{
		std::unique_ptr<Factory> factory = std::make_unique<UIFactory>();
		
		UI* mainUI = static_cast<UI*>(factory->CreateObject(new UI("Main")
			, Math::Vector2(600.0f, 300.0f), Math::Vector2(700.0f, 600.0f)));
		mainUI->SetLayout(new FlowLayout);
		AddGameObject(eLayerType::UI, mainUI);

		UI* dragUI = static_cast<UI*>(factory->CreateObject(new UI("Drag")));
		dragUI->SetMoveComponent(new MouseUIMove);
		dragUI->SetSize(Math::Vector2(700.0f, 50.0f));
		if (mainUI->AddChildUI(dragUI) == false)
			delete dragUI;

		UI* ui = static_cast<UI*>(factory->CreateObject(new UI("ChangeScene")));
		ui->SetPressedClickEvent(new ChangeSceneEvent("Test2"));
		ui->SetSize(Math::Vector2(50.0f, 50.0f));
		if (mainUI->AddChildUI(ui) == false)
			delete ui;

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
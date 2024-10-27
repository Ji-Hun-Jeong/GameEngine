#include "UI.h"
#include "TransformComponent.h"
#include "BasicRenderer.h"

namespace Game
{
	UI::UI(const std::string& name)
		: GameObject(name)
		, m_OwnerUI(nullptr)
		, m_CurFocus(false)
	{
		m_VecChildUI.reserve(10);
	}
	UI::~UI()
	{
		Utility::DeleteVector<UI*>(m_VecChildUI);
	}
	void UI::Update(float dt)
	{
		GameObject::Update(dt);
		for (int i = 0; i < m_VecChildUI.size(); ++i)
			m_VecChildUI[i]->Update(dt);
	}
	void UI::PostUpdate(float dt, Camera* const curCamera)
	{
		GameObject::PostUpdate(dt, curCamera);

		for (int i = 0; i < m_VecChildUI.size(); ++i)
			m_VecChildUI[i]->PostUpdate(dt, curCamera);
	}
	void UI::Render(HDC dc)
	{
		GameObject::Render(dc);

		for (int i = 0; i < m_VecChildUI.size(); ++i)
			m_VecChildUI[i]->Render(dc);
	}
	void UI::AddChildUI(UI* const ui)
	{
		ui->m_OwnerUI = this;
		m_VecChildUI.push_back(ui);
	}
	void UI::EnterMouse()
	{
		BasicRenderer* rederer = dynamic_cast<BasicRenderer*>(m_RenderComponent);
		if (rederer)
			rederer->SetWidth(3.0f);
		m_CurFocus = true;
		//std::cout << m_Name + "EnterMouse\n";
	}
	void UI::OnMouse()
	{
		//std::cout << m_Name + "OnMouse\n";
	}
	void UI::ExitMouse()
	{
		BasicRenderer* rederer = dynamic_cast<BasicRenderer*>(m_RenderComponent);
		if (rederer)
			rederer->SetWidth(1.0f);
		m_CurFocus = false;
		//std::cout << m_Name + "ExitMouse\n";
	}
}


#include "UI.h"
#include "TransformComponent.h"

namespace Game
{
	UINT UI::s_numOfUI = 0;
	UI::UI()
		: GameObject("UI" + std::to_string(s_numOfUI++))
		, m_OwnerUI(nullptr)
		, m_PrevOn(false)
	{
		m_VecChildUI.reserve(10);
	}
	UI::~UI()
	{
		Utility::DeleteVector<UI*>(m_VecChildUI);
	}
	void UI::Update(float dt)
	{
		if (m_OwnerUI)
			m_TransformComponent->SetPos(m_OwnerUI->GetPos());

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
		std::cout << m_Name + "EnterMouse\n";
	}
	void UI::OnMouse()
	{
		std::cout << m_Name + "OnMouse\n";
	}
	void UI::ExitMouse()
	{
		std::cout << m_Name + "ExitMouse\n";
	}
}


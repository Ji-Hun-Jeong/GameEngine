#include "UI.h"
#include "TransformComponent.h"
#include "BasicRenderer.h"
#include "Layout.h"
#include "MouseMgr.h"
#include "Event.h"

namespace Game
{
	UI::UI(const std::string& name)
		: GameObject(name)
		, m_OwnerUI(nullptr)
		, m_Layout(nullptr)
		, m_PressedEvent(nullptr)
		, m_ReleasedEvent(nullptr)
		, m_CurFocus(false)
	{
		m_VecChildUI.reserve(10);
	}

	UI::UI(const UI& other)
		: GameObject(other)
		, m_OwnerUI(other.m_OwnerUI)
		, m_Layout(other.m_Layout->GetClone())
		, m_CurFocus(other.m_CurFocus)
	{
		m_VecChildUI.reserve(other.m_VecChildUI.capacity());
		for (size_t i = 0; i < other.m_VecChildUI.size(); ++i)
			m_VecChildUI.push_back(other.m_VecChildUI[i]->GetClone());
	}

	UI::~UI()
	{
		Utility::DeleteVector<UI*>(m_VecChildUI);
		if (m_Layout)
			delete m_Layout;
		if (m_PressedEvent)
			delete m_PressedEvent;
		if (m_ReleasedEvent)
			delete m_ReleasedEvent;
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

	bool UI::AddChildUI(UI* const ui)
	{
		bool permitAttach = true;

		if (m_Layout)
			permitAttach = m_Layout->PlaceUI(this, ui);
		else
			permitAttach = Layout::IsPossibleInParentUI(GetSize(), ui->GetSize(), ui->GetOffset());

		if (permitAttach)
		{
			ui->m_OwnerUI = this;
			m_VecChildUI.push_back(ui);
		}
		return permitAttach;
	}

	void UI::SetPressedClickEvent(Event* const pressedClickEvent)
	{
		if (m_PressedEvent)
			delete m_PressedEvent;
		m_PressedEvent = pressedClickEvent;
	}

	void UI::SetReleasedClickEvent(Event* const releasedClickEvent)
	{
		if (m_ReleasedEvent)
			delete m_ReleasedEvent;
		m_ReleasedEvent = releasedClickEvent;
	}
	
	void UI::EnterMouse()
	{
		BasicRenderer* rederer = dynamic_cast<BasicRenderer*>(m_RenderComponent);
		if (rederer)
			rederer->SetWidth(3.0f);
		m_CurFocus = true;
	}

	void UI::OnMouse()
	{
		static MouseMgr& mouseMgr = MouseMgr::GetInst();

		if (mouseMgr.GetMouseState(eButtonState::Tap))
			this->onClick();
		else if (mouseMgr.GetMouseState(eButtonState::Released))
			this->releasedClick();
	}

	void UI::ExitMouse()
	{
		BasicRenderer* rederer = dynamic_cast<BasicRenderer*>(m_RenderComponent);
		if (rederer)
			rederer->SetWidth(1.0f);
		m_CurFocus = false;
	}

	void UI::onClick()
	{
		if (m_PressedEvent)
			m_PressedEvent->Execute();
	}

	void UI::releasedClick()
	{
		if (m_ReleasedEvent)
			m_ReleasedEvent->Execute();
	}
}


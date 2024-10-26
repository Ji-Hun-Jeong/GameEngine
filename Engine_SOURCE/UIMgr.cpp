#include "UIMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "MouseMgr.h"
#include "Component.h"
#include "UI.h"

namespace Game
{
	UIMgr::UIMgr()
		: m_PrevFocusUI(nullptr)
	{
		m_VecCurOnUI.reserve(30);
	}
	UIMgr::~UIMgr()
	{

	}

	void UIMgr::Update()
	{
		const std::map<std::string, GameObject*>& uiMap =
			SceneMgr::GetInst().GetCurScene()->GetGameObject(eLayerType::UI);

		std::queue<GameObject*> uiQueue;
		for (auto iter = uiMap.begin(); iter != uiMap.end(); ++iter)
			uiQueue.push(iter->second);

		UI* focusUI = getFocusUI(uiQueue);

		if (focusUI)
		{
			bool isPrevOn = focusUI->IsPrevFocus();
			if (isPrevOn)
			{
				if (focusUI != m_PrevFocusUI)
					focusUI->EnterMouse();

				focusUI->OnMouse();
			}
				
			else
			{
				if (m_PrevFocusUI)
					m_PrevFocusUI->ExitMouse();

				focusUI->EnterMouse();	
			}

			for (auto ui : m_VecCurOnUI)
				ui->SetPrevFocus(true);
			m_VecCurOnUI.clear();
		}

		m_PrevFocusUI = focusUI;
	}

	UI* UIMgr::getFocusUI(std::queue<GameObject*>& uiQueue)
	{
		const Math::Vector2& mousePos = MouseMgr::GetInst().GetMousePos();

		auto onMouse = [mousePos](GameObject* ui)->bool
			{
				Gdiplus::Rect rect = Component::GetRectInMYC(ui->GetFinalPos(), ui->GetSize());

				if (rect.GetLeft() <= mousePos.x && mousePos.x <= rect.GetRight()
					&& rect.GetTop() <= mousePos.y && mousePos.y <= rect.GetBottom())
					return true;

				return false;
			};

		UI* focusUI = nullptr;
		while (uiQueue.empty() == false)
		{
			UI* ui = static_cast<UI*>(uiQueue.front());
			uiQueue.pop();

			bool mouseInUI = onMouse(ui);
			if (mouseInUI == false)
			{
				if (ui->IsPrevFocus())
					ui->ExitMouse();
				ui->SetPrevFocus(false);
				continue;
			}

			m_VecCurOnUI.push_back(ui);

			const std::vector<UI*>& childUI = ui->GetChildUI();
			for (int i = 0; i < childUI.size(); ++i)
			{
				UI* child = childUI[i];
				uiQueue.push(child);
			}

			focusUI = ui;
		}
		return focusUI;
	}
}
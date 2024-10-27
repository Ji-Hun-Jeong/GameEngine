#include "UIMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "MouseMgr.h"
#include "Component.h"
#include "UI.h"

namespace Game
{
	UIMgr::UIMgr()
		: m_CurFocusUI(nullptr)
		, m_PrevFocusUI(nullptr)
	{
		
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

		m_CurFocusUI = getFocusUI(uiQueue);

		if (m_CurFocusUI == m_PrevFocusUI)
		{
			if (m_CurFocusUI)
				m_CurFocusUI->OnMouse();
		}
		else
		{
			if (m_CurFocusUI)
				m_CurFocusUI->EnterMouse();
			if (m_PrevFocusUI)
				m_PrevFocusUI->ExitMouse();
		}

		m_PrevFocusUI = m_CurFocusUI;
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
				continue;

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
#pragma once
#include "GameObject.h"
namespace Game
{
	class UI : public GameObject
	{
		CLONE(UI, UI)
	public:
		UI(const std::string& name);
		UI(const UI& other);
		virtual ~UI();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera) override;
		void Render(HDC dc) override;

		void EnterMouse();
		void OnMouse();
		void ExitMouse();
		

		bool AddChildUI(UI* const ui);
		void SetLayout(class Layout* const layout) { m_Layout = layout; }
		void SetPressedClickEvent(class Event* const pressedClickEvent);
		void SetReleasedClickEvent(class Event* const releasedClickEvent);

		UI* GetOwnerUI() { return m_OwnerUI; }
		const std::vector<UI*>& GetChildUI() const { return m_VecChildUI; }

		bool IsCurFocus() { return m_CurFocus; }

	private:
		void onClick();
		void releasedClick();

	protected:
		class Layout* m_Layout;

		class Event* m_PressedEvent;
		class Event* m_ReleasedEvent;
		std::vector<UI*> m_VecChildUI;
		UI* m_OwnerUI;

		bool m_CurFocus;
	};
}



#pragma once
#include "GameObject.h"
namespace Game
{
	class UI : public GameObject
	{
	protected:
		UI(const std::string& name);
		UI(const UI& other);

	public:
		virtual ~UI();

	public:
		virtual UI* GetClone() const = 0;
		virtual void Update(float dt) override;
		virtual void PostUpdate(float dt, Camera* const curCamera) override;
		virtual void Render(HDC dc) override;
		virtual void EnterMouse();
		virtual void OnMouse();
		virtual void ExitMouse();

		void AddChildUI(UI* const ui);
		void SetLayout(class Layout* const layout) { m_Layout = layout; }

		UI* GetOwnerUI() { return m_OwnerUI; }
		const std::vector<UI*>& GetChildUI() const { return m_VecChildUI; }

		bool IsCurFocus() { return m_CurFocus; }

	protected:
		class Layout* m_Layout;

		std::vector<UI*> m_VecChildUI;
		UI* m_OwnerUI;

		bool m_CurFocus;
	};
}



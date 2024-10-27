#pragma once
#include "GameObject.h"
namespace Game
{
	class UI : public GameObject
	{
		CLONE(GameObject, UI)
	protected:
		UI(const std::string& name);
		UI(const UI& other) = default;

	public:
		~UI();

	public:
		virtual void Update(float dt) override;
		virtual void PostUpdate(float dt, Camera* const curCamera) override;
		virtual void Render(HDC dc) override;
		virtual void EnterMouse();
		virtual void OnMouse();
		virtual void ExitMouse();

		void AddChildUI(UI* const ui);

		UI* GetOwnerUI() { return m_OwnerUI; }
		const std::vector<UI*>& GetChildUI() const { return m_VecChildUI; }

		bool IsCurFocus() { return m_CurFocus; }

	protected:
		std::vector<UI*> m_VecChildUI;
		UI* m_OwnerUI;

		bool m_CurFocus;
	};
}



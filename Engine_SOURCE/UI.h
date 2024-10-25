#pragma once
#include "GameObject.h"
namespace Game
{
	class UI : public GameObject
	{
		CLONE(GameObject, UI)
	public:
		UI();
		UI(const UI& other) = default;
		~UI();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera) override;
		void Render(HDC dc) override;

		void AddChildUI(UI* const ui);

		void EnterMouse();
		void OnMouse();
		void ExitMouse();

		const std::vector<UI*>& GetChildUI() const { return m_VecChildUI; }

		void SetCurOn(bool curOn) { m_CurOn = curOn; }
		bool IsCurOn() { return m_CurOn; }
		void SetPrevOn(bool prevOn) { m_PrevOn = prevOn; }
		bool IsPrevOn() { return m_PrevOn; }

	protected:
		std::vector<UI*> m_VecChildUI;
		UI* m_OwnerUI;

		bool m_CurOn;
		bool m_PrevOn;

		static UINT s_numOfUI;
	};
}



#pragma once
#include "GameObject.h"
#include "MouseDrager.h"

namespace Game
{
	class RenderComponent;
	class AnimationGenerator : public GameObject
	{
	public:
		AnimationGenerator();
		~AnimationGenerator();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera) override;
		void Render(HDC dc) override;

	private:
		MouseDrager m_MouseDrager;
		std::vector<Gdiplus::Rect> m_VecAnimateFrames;
		std::vector<Gdiplus::Rect> m_VecFinalFramesInfo;
	};
}



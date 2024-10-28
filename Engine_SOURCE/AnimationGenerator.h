#pragma once
#include "GameObject.h"
#include "RectGenerator.h"

namespace Game
{
	class RenderComponent;
	class Frame;
	class AnimationGenerator : public GameObject
	{
		CLONE(GameObject, AnimationGenerator)
	public:
		AnimationGenerator();
		AnimationGenerator(const AnimationGenerator& other);
		~AnimationGenerator();

	public:
		void Update(float dt) override;
		void PostUpdate(float dt, Camera* const curCamera) override;
		void Render(HDC dc) override;

	private:
		RectGenerator m_MouseDrager;
		std::vector<Frame*> m_VecFrames;
		std::vector<Gdiplus::Rect> m_VecFramesInfo;
		std::string m_AnimationName;

	};
}



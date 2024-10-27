#pragma once
#include "RenderComponent.h"

namespace Game
{
	class Animator : public RenderComponent
	{
		CLONE(RenderComponent, Animator)
	public:
		Animator();
		Animator(const Animator& other);
		~Animator();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;
		void AddAnimation(class Animation* const animation);

	private:
		std::map<std::string, class Animation*> m_MapAnimations;
	};
}



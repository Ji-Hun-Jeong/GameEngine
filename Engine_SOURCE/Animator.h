#pragma once
#include "RenderComponent.h"
namespace Game
{
	class Animation;
	class Animator : public RenderComponent
	{
	public:
		explicit Animator(GameObject* owner);
		virtual ~Animator();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;
		void AddAnimation(Animation* const animation);

	private:
		std::map<std::string, Animation*> m_MapAnimations;
	};
}



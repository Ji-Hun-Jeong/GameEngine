#pragma once
#include "Component.h"
namespace Game
{
	class MouseEventReceiver : public Component
	{
	public:
		MouseEventReceiver();
		~MouseEventReceiver();

	public:
		void DoSomething(class GameObject* const owner) override;

	};
}



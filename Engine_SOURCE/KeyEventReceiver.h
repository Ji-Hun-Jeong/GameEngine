#pragma once
#include "Component.h"
namespace Game
{
	class KeyEventReceiver : public Component
	{
	public:
		KeyEventReceiver();
		~KeyEventReceiver();

	private:
		void DoSomething(class GameObject* const owner) override;

	};
}



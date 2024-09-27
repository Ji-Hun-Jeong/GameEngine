#pragma once
#include "Component.h"
namespace Game
{
	class PlayerKeyMove : public Component
	{
	public:
		PlayerKeyMove();
		~PlayerKeyMove();

	public:
		void DoSomething(GameObject* const owner) override;

	private:

	};
}



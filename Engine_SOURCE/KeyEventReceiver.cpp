#include "KeyEventReceiver.h"
#include "KeyMgr.h"

namespace Game
{
	KeyEventReceiver::KeyEventReceiver()
		: Component("KER")
	{
	}
	KeyEventReceiver::~KeyEventReceiver()
	{
	}
	void KeyEventReceiver::DoSomething(GameObject* const owner)
	{
		if (KeyMgr::GetInst().GetKeyState(eKeyType::Q, eButtonState::Tap))
			std::cout << "Q Tap!\n";
	}
}


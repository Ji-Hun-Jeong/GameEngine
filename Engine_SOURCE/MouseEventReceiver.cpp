#include "MouseEventReceiver.h"
#include "MouseMgr.h"

namespace Game
{
	MouseEventReceiver::MouseEventReceiver()
		: Component("MER")
	{
	}
	MouseEventReceiver::~MouseEventReceiver()
	{
	}
	void MouseEventReceiver::DoSomething(GameObject* const owner)
	{
		if (MouseMgr::GetInst().GetMouseState(eButtonState::Tap))
			std::cout << "MouseTap!\n";
	}
}
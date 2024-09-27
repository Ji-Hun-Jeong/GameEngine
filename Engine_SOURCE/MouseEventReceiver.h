#pragma once
#include "EventReceiver.h"
namespace Game
{
	namespace Event
	{
		class MouseEventReceiver : public IEventReceiver
		{
		public:
			MouseEventReceiver() = default;
			~MouseEventReceiver() = default;

		public:
			void Update() override;

		};
	}
}



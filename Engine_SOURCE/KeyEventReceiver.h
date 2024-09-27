#pragma once
#include "EventReceiver.h"
namespace Game
{
	namespace Event
	{
		class KeyEventReceiver : public IEventReceiver
		{
		public:
			KeyEventReceiver() = default;
			~KeyEventReceiver() = default;

		public:
			void Update() override;

		private:

		};
	}
}



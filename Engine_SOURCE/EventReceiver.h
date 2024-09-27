#pragma once
namespace Game
{
	namespace Event
	{
		class IEventReceiver
		{
		public:
			IEventReceiver() = default;
			virtual ~IEventReceiver() = default;

		public:
			virtual void Update() = 0;
		};
	}
}



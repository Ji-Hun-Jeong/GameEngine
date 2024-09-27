#pragma once
#include "Common.h"
#include "EventReceiver.h"
namespace Game
{
	namespace Event
	{
		enum class eEventType
		{
			Mouse,
			Key,
			End,
		};
		class EventMgr
		{
			SINGLE(EventMgr)
		public:
			void Initalize();
			void Update();

		private:
			IEventReceiver* m_ArrEventReceiver[(UINT)eEventType::End];
		};
	}
}
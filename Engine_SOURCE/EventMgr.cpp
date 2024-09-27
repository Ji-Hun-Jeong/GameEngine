#include "EventMgr.h"
#include "KeyEventReceiver.h"
#include "MouseEventReceiver.h"
namespace Game
{
	namespace Event
	{
		EventMgr::EventMgr()
			: m_ArrEventReceiver{ nullptr }
		{}
		EventMgr::~EventMgr()
		{
			Game::Utility::SafeDeleteArr<Game::Event::IEventReceiver*>(m_ArrEventReceiver
				, (UINT)eEventType::End);
		}
		void EventMgr::Initalize()
		{
			m_ArrEventReceiver[(UINT)eEventType::Mouse] = new MouseEventReceiver;
			m_ArrEventReceiver[(UINT)eEventType::Key] = new KeyEventReceiver;
		}
		void EventMgr::Update()
		{
			for (UINT i = 0; i < (UINT)eEventType::End; ++i)
				m_ArrEventReceiver[i]->Update();
		}
	}
}
#pragma once
#include "Event.h"
namespace Game
{
	class ChangeSceneEvent : public Event
	{
	public:
		ChangeSceneEvent(const std::string& toChangeSceneName);
		ChangeSceneEvent(const Entity& other);
		~ChangeSceneEvent();

	public:
		void Execute() override;

	private:
		std::string m_ToChangeSceneName;

	};
}



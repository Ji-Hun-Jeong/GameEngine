#include "ChangeSceneEvent.h"
#include "SceneMgr.h"

namespace Game
{
	ChangeSceneEvent::ChangeSceneEvent(const std::string& toChangeSceneName)
		: Event("ChangeScene")
		, m_ToChangeSceneName(toChangeSceneName)
	{
	}
	ChangeSceneEvent::ChangeSceneEvent(const Entity& other)
		: Event(other)
	{
	}
	ChangeSceneEvent::~ChangeSceneEvent()
	{
	}
	void ChangeSceneEvent::Execute()
	{
		static SceneMgr& sceneMgr = SceneMgr::GetInst();
		sceneMgr.RequestChangeScene(m_ToChangeSceneName);
	}
}
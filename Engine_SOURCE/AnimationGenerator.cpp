#include "AnimationGenerator.h"
#include "Camera.h"
#include "Frame.h"
#include "KeyMgr.h"
#include "PathMgr.h"
#include "FileMgr.h"

namespace Game
{
	AnimationGenerator::AnimationGenerator()
		: GameObject("AnimationGenerator")
		, m_AnimationName("Attack")
	{
		m_VecFrames.reserve(10);
	}
	AnimationGenerator::AnimationGenerator(const AnimationGenerator& other)
		: GameObject(other)
		, m_MouseDrager(other.m_MouseDrager)
		, m_VecFramesInfo(other.m_VecFramesInfo)
		, m_AnimationName(other.m_AnimationName)
	{
		m_VecFrames.resize(other.m_VecFrames.size(), nullptr);
		for (size_t i = 0; i < other.m_VecFrames.size(); ++i)
		{
			m_VecFrames[i] = new Frame(*other.m_VecFrames[i]);
		}
	}
	AnimationGenerator::~AnimationGenerator()
	{
		Utility::DeleteVector<Frame*>(m_VecFrames);
	}
	void AnimationGenerator::Update(float dt)
	{
		GameObject::Update(dt);
		m_MouseDrager.Update(dt);
		static KeyMgr& keyMgr = KeyMgr::GetInst();
		if (keyMgr.GetKeyState(eKeyType::Ctrl, eButtonState::Hold) &&
			keyMgr.GetKeyState(eKeyType::Z, eButtonState::Tap) && m_VecFrames.empty() == false)
		{
			delete m_VecFrames[m_VecFrames.size() - 1];
			m_VecFrames.pop_back();
		}
	}
	void AnimationGenerator::PostUpdate(float dt, Camera* const curCamera)
	{
		GameObject::PostUpdate(dt, curCamera);

		for (size_t i = 0; i < m_VecFrames.size(); ++i)
			m_VecFrames[i]->PostUpdate(dt, curCamera);

		m_MouseDrager.PostUpdate(dt, curCamera);
		if (m_MouseDrager.IsCompleteMakeRect())
		{
			m_VecFrames.push_back(new Frame(m_AnimationName, UINT(m_VecFrames.size())
				, m_MouseDrager.GetDragedRect()));
		}

		static KeyMgr& keyMgr = KeyMgr::GetInst();
		if (keyMgr.GetKeyState(eKeyType::Ctrl, eButtonState::Hold) &&
			keyMgr.GetKeyState(eKeyType::S, eButtonState::Tap))
		{
			m_VecFramesInfo.resize(m_VecFrames.size());
			const Gdiplus::Rect rect = curCamera->GetFinalRectInMYC();
			for (size_t i = 0; i < m_VecFrames.size(); ++i)
			{
				m_VecFramesInfo[i] = Component::GetRectInMYC(m_VecFrames[i]->GetFinalPos()
					, m_VecFrames[i]->GetSize());
				m_VecFramesInfo[i].X += rect.X;
				m_VecFramesInfo[i].Y += rect.Y;
			}
			FileMgr::GetInst().SaveToFileByVector<Gdiplus::Rect>(m_VecFramesInfo);
			Utility::DeleteVector<Frame*>(m_VecFrames);
			m_VecFramesInfo.clear();
		}
	}
	void AnimationGenerator::Render(HDC dc)
	{
		GameObject::Render(dc);

		for (size_t i = 0; i < m_VecFrames.size(); ++i)
			m_VecFrames[i]->Render(dc);

		m_MouseDrager.Render(dc);
	}
}
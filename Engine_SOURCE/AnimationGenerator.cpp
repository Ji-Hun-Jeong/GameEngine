#include "AnimationGenerator.h"
#include "BasicRenderer.h"
#include "Camera.h"
#include "Component.h"
#include "Frame.h"

namespace Game
{
	AnimationGenerator::AnimationGenerator()
		: GameObject("AnimationGenerator")
		, m_AnimationName("Attack")
	{
		SetRenderComponent(new BasicRenderer(this));
		m_VecFrames.reserve(10);
		//m_VecAnimateFrames.reserve(10);
	}
	AnimationGenerator::~AnimationGenerator()
	{
		Utility::DeleteVector<Frame*>(m_VecFrames);
	}
	void AnimationGenerator::Update(float dt)
	{
		GameObject::Update(dt);
		m_MouseDrager.Update(dt);
	}
	void AnimationGenerator::PostUpdate(float dt, Camera* const curCamera)
	{
		GameObject::PostUpdate(dt, curCamera);

		for (size_t i = 0; i < m_VecFrames.size(); ++i)
			m_VecFrames[i]->PostUpdate(dt, curCamera);

		m_MouseDrager.PostUpdate(dt, curCamera);
		if (m_MouseDrager.IsCompleteMakeRect())
		{
			m_VecFrames.push_back(new Frame(m_AnimationName, m_VecFrames.size()
				, m_MouseDrager.GetDragedRect()));
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
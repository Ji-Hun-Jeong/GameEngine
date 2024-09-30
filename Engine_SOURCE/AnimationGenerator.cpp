#include "AnimationGenerator.h"
#include "BasicRenderer.h"
#include "Camera.h"
#include "Component.h"

namespace Game
{
	AnimationGenerator::AnimationGenerator()
		: GameObject("AnimationGenerator")
	{
		SetRenderComponent(new BasicRenderer(this));
		m_VecAnimateFrames.reserve(10);
	}
	AnimationGenerator::~AnimationGenerator()
	{
	}
	void AnimationGenerator::Update(float dt)
	{
		GameObject::Update(dt);
		m_MouseDrager.Update(dt);
		if (m_MouseDrager.IsCompleteMakeRect())
		{
			m_VecAnimateFrames.push_back(m_MouseDrager.GetDragedRect());
			m_VecFinalFramesInfo.resize(m_VecAnimateFrames.size());
		}
	}
	void AnimationGenerator::PostUpdate(float dt, Camera* const curCamera)
	{
		GameObject::PostUpdate(dt, curCamera);
		const Math::Vector2& cameraPos = curCamera->GetPos();
		const Math::Vector2& cameraSize = curCamera->GetSize();
		RECT newRect = Component::TransformMYC(cameraPos, cameraSize);
		if (m_MouseDrager.IsCompleteMakeRect())
		{
			m_VecAnimateFrames.back().X += newRect.left;
			m_VecAnimateFrames.back().Y += newRect.top;
		}
		for (size_t i = 0; i < m_VecAnimateFrames.size(); ++i)
		{
			m_VecFinalFramesInfo[i].X = m_VecAnimateFrames[i].X - newRect.left;
			m_VecFinalFramesInfo[i].Y = m_VecAnimateFrames[i].Y - newRect.top;
			m_VecFinalFramesInfo[i].Width = m_VecAnimateFrames[i].Width;
			m_VecFinalFramesInfo[i].Height = m_VecAnimateFrames[i].Height;
		}
		m_MouseDrager.PostUpdate(dt, curCamera);
	}
	void AnimationGenerator::Render(HDC dc)
	{
		GameObject::Render(dc);
		assert(m_RenderComponent);
		for (size_t i = 0; i < m_VecFinalFramesInfo.size(); ++i)
		{
			const Gdiplus::Rect rect = m_VecFinalFramesInfo[i];
			m_RenderComponent->Render(dc
				, Math::Vector2(float(rect.X), float(rect.Y))
				, Math::Vector2(float(rect.Width), float(rect.Height)));
		}
		m_MouseDrager.Render(dc);
	}
}
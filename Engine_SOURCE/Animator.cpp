#include "Animator.h"
#include "TimeMgr.h"
#include "FileMgr.h"

namespace Game
{
	Animator::Animator(float changeTime)
		: RenderComponent("Animator")
		, m_ChangeTime(changeTime)
		, m_MeasureTime(0.0f)
	{
		m_VecTextureCutInfo.reserve(10);
	}
	Animator::~Animator()
	{
	}
	void Animator::Render(HDC dc, const TransformComponent* const transform)
	{
		assert(m_Texture);
		m_MeasureTime += TimeMgr::GetInst().DeltaTime();
		if (m_ChangeTime < m_MeasureTime)
		{
			m_AnimateFrame += 1;
			m_AnimateFrame = m_AnimateFrame >= m_VecTextureCutInfo.size() ? 0 : m_AnimateFrame;
			m_MeasureTime = 0.0f;
		}

		Gdiplus::Rect finalRect = transform->GetFinalRectInMYC();
		const Gdiplus::Rect& cutInfo = m_VecTextureCutInfo[m_AnimateFrame];

		TransparentBlt(dc, finalRect.X, finalRect.Y, finalRect.Width, finalRect.Height
			, m_Texture->GetBitmapDc()
			, cutInfo.X, cutInfo.Y
			, cutInfo.Width, cutInfo.Height, MAGENTA);
	}
	void Animator::AddTextureCutInfoByFile(const std::string& fileName)
	{
		FileMgr::GetInst().SaveToVectorByFile<Gdiplus::Rect>(m_VecTextureCutInfo, fileName);
	}
}
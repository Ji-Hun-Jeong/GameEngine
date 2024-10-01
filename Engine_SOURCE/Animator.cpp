#include "Animator.h"
#include "TimeMgr.h"

namespace Game
{
	Animator::Animator(GameObject* const owner, float changeTime)
		: RenderComponent("Animator", owner)
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

		const Math::Vector2& pos = transform->GetFinalPos();
		const Math::Vector2& size = transform->GetSize();
		UINT sizeX = static_cast<UINT>(size.x);
		UINT sizeY = static_cast<UINT>(size.y);
		RECT newRect = TransformMYC(pos, size);
		const Gdiplus::Rect& cutInfo = m_VecTextureCutInfo[m_AnimateFrame];

		TransparentBlt(dc, newRect.left, newRect.top, sizeX, sizeY
			, m_Texture->GetBitmapDc()
			, cutInfo.X, cutInfo.Y
			, cutInfo.Width, cutInfo.Height, MAGENTA);
	}
}
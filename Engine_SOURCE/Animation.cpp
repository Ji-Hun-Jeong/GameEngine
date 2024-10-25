#include "Animation.h"
#include "TransformComponent.h"
#include "TimeMgr.h"
#include "FileMgr.h"
#include "Texture.h"
#include "ResourceMgr.h"

namespace Game
{
	Animation::Animation(const std::string& name, float changeTime)
		: Entity(name)
		, m_AnimateFrame(0)
		, m_ChangeTime(changeTime)
		, m_MeasureTime(0.0f)
		, m_Texture(nullptr)
	{
		m_VecTextureCutInfo.reserve(10);
	}

	Animation::Animation(const Animation& other)
		: Entity(other)
		, m_VecTextureCutInfo(other.m_VecTextureCutInfo)
		, m_AnimateFrame(other.m_AnimateFrame)
		, m_ChangeTime(other.m_ChangeTime)
		, m_MeasureTime(other.m_MeasureTime)
		, m_Texture(other.m_Texture)
	{
	}

	Animation::~Animation()
	{
	}
	void Animation::SetTexture(const std::string& textureName)
	{
		// 미리 전부 로딩을 해놓고 ResourceMgr에게 받아서 쓰는 것
		m_Texture = dynamic_cast<Texture*>(
			ResourceMgr::GetInst().GetResource(eResourceType::Texture, textureName));

		assert(m_Texture);
	}
	void Animation::Render(HDC dc, const TransformComponent* const transform)
	{
		m_FinishAnimation = false;
		m_MeasureTime += TimeMgr::GetInst().DeltaTime();

		if (m_AnimateFrame == m_VecTextureCutInfo.size())
			m_FinishAnimation = true;

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

	void Animation::AddTextureCutInfoByFile(const std::string& fileName)
	{
		FileMgr::GetInst().SaveToVectorByFile<Gdiplus::Rect>(m_VecTextureCutInfo, fileName);
	}
}


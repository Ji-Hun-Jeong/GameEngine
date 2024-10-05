#pragma once
#include "RenderComponent.h"
namespace Game
{
	class Animator : public RenderComponent
	{
	public:
		explicit Animator(GameObject* owner, float changeTime);
		virtual ~Animator();

	public:
		void Render(HDC dc, const TransformComponent* const transform) override;
		void AddTextureCutInfo(const Gdiplus::Rect& cutInfo) { m_VecTextureCutInfo.push_back(cutInfo); }
		void AddTextureCutInfoByFile(const std::string& fileName);
		void SetChangeTime(float changeTime) { m_ChangeTime = changeTime; }

	private:
		std::vector<Gdiplus::Rect> m_VecTextureCutInfo;
		size_t m_AnimateFrame = 0;
		float m_ChangeTime;
		float m_MeasureTime;
	};
}



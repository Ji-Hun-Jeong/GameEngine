#pragma once
#include "Entity.h"
namespace Game
{
	class TransformComponent;
	class Texture;
	class Animation : public Entity
	{
	public:
		explicit Animation(const std::string& name, float changeTime);
		Animation(const Animation& other);
		~Animation();

	public:
		void Render(HDC dc, const TransformComponent* const transform);
		void SetTexture(const std::string& textureName);
		void AddTextureCutInfoByFile(const std::string& fileName);
		void AddTextureCutInfo(const Gdiplus::Rect& cutInfo) { m_VecTextureCutInfo.push_back(cutInfo); }
		void SetChangeTime(float changeTime) { m_ChangeTime = changeTime; }
		float GetChangeTime() { return m_ChangeTime; }

	private:
		std::vector<Gdiplus::Rect> m_VecTextureCutInfo;
		size_t m_AnimateFrame;
		float m_ChangeTime;
		float m_MeasureTime;
		bool m_FinishAnimation;

		Texture* m_Texture;
	};
}



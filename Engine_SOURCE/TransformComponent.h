#pragma once
#include "Component.h"
namespace Game
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent(const Math::Vector2& pos, const Math::Vector2& size);
		TransformComponent(const TransformComponent&) = default;
		virtual ~TransformComponent();

	public:
		virtual TransformComponent* GetClone() const = 0;
		virtual void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) = 0;

		void SetPos(const Math::Vector2& pos) { m_Pos = pos; }
		void SetSize(const Math::Vector2& size) { m_Size = size; }

		const Math::Vector2& GetPos() const { return m_Pos; }
		const Math::Vector2& GetFinalPos() const { return m_FinalPos; }
		const Math::Vector2& GetSize() const { return m_Size; }

		void CopyValue(TransformComponent* const other) const;

		Gdiplus::Rect GetFinalRectInMYC() const;

	protected:
		Math::Vector2 m_Pos;
		Math::Vector2 m_FinalPos;
		Math::Vector2 m_Size;

	};
}



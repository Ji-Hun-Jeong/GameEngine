#pragma once
#include "Component.h"
namespace Game
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent();
		TransformComponent(const Math::Vector2& pos, const Math::Vector2& size);
		TransformComponent(const TransformComponent&) = default;
		virtual ~TransformComponent();

	public:
		virtual TransformComponent* GetClone() const = 0;
		virtual void TransformByCamera(float dt, const TransformComponent* const curCameraTransform) = 0;
		void AdjustByOffset();

		void SetPos(const Math::Vector2& pos) { m_Pos = pos; }
		void SetSize(const Math::Vector2& size) { m_Size = size; }
		void SetOffset(const Math::Vector2& offset) { m_Offset = offset; }
		void AddOffset(const Math::Vector2& offset) { m_Offset += offset; }

		const Math::Vector2& GetPos() const { return m_Pos; }
		const Math::Vector2& GetFinalPos() const { return m_FinalPos; }
		const Math::Vector2& GetSize() const { return m_Size; }
		const Math::Vector2& GetOffset() const { return m_Offset; }
		const Math::Vector2& GetPrevOffset() const { return m_PrevOffset; }

		void CopyValue(TransformComponent* const other) const;

		Gdiplus::Rect GetFinalRectInMYC() const;

	protected:
		Math::Vector2 m_Pos;
		Math::Vector2 m_Offset;
		Math::Vector2 m_PrevOffset;
		Math::Vector2 m_FinalPos;
		Math::Vector2 m_Size;

	};
}



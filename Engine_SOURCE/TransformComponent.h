#pragma once
#include "Component.h"
namespace Game
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent(const std::string& name, GameObject* const owner
			, const Math::Vector2& pos, const Math::Vector2& size);
		virtual ~TransformComponent();

	public:
		virtual void Update(float dt) = 0;

		void SetPos(const Math::Vector2& pos) { m_Pos = pos; }
		void SetSize(const Math::Vector2& size) { m_Size = size; }
		const Math::Vector2& GetPos() const { return m_Pos; }
		const Math::Vector2& GetSize() const { return m_Size; }

	protected:
		Math::Vector2 m_Pos;
		Math::Vector2 m_Size;

	};
}



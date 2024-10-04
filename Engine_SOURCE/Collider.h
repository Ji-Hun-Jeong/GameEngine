#pragma once
#include "Component.h"
namespace Game
{
	class TransformComponent;
	class RenderComponent;
	class Player;
	class BackGround;
	class Collider : public Component, public CollisionFunc
	{
	public:
		Collider();
		~Collider();

	public:
		void Update(float dt, const TransformComponent* const ownerTransformComponent);
		void Render(HDC dc);

		const Math::Vector2& GetColliderPos() const;
		const Math::Vector2& GetColliderFinalPos() const;
		const Math::Vector2& GetColliderSize() const;

	protected:
		TransformComponent* m_TransformComponent;
		RenderComponent* m_RenderComponent;
		bool m_PermitRender;

		bool m_OnCollision;



	};
}



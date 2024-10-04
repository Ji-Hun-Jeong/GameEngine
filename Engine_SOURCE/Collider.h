#pragma once
#include "Component.h"
namespace Game
{
	class TransformComponent;
	class RenderComponent;
	class Collider : public Component
	{
	public:
		Collider(GameObject* const owner, TransformComponent* const transformComponent
		, RenderComponent* const renderComponent);
		~Collider();

	public:
		void Update(float dt, const TransformComponent* const ownerTransformComponent);
		void Render(HDC dc);

	protected:
		TransformComponent* m_TransformComponent;
		RenderComponent* m_RenderComponent;
		bool m_PermitRender;

	};
}



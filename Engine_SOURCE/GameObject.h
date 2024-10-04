#pragma once
#include "Common.h"
#include "Entity.h"
#include "CollisionFunc.h"

namespace Game
{
	class Component;
	class TransformComponent;
	class RenderComponent;
	class Camera;
	class Collider;
	class GameObject : public Entity
	{
	public:
		GameObject(const std::string& name);
		virtual ~GameObject() = 0;

	public:
		virtual void Update(float dt);
		virtual void PostUpdate(float dt, Camera* const curCamera);
		virtual void Render(HDC dc);
		
		void SetTransformComponent(TransformComponent* const transformComponent);
		void SetRenderComponent(RenderComponent* const renderComponent);
		void SetCollider(Collider* const collider);

		void SetTexture(const std::string& textureName);
		void SetPos(const Math::Vector2& pos);
		void SetSize(const Math::Vector2& size);
		void SetSizeFromTexture();

		const Math::Vector2& GetPos() const;
		const Math::Vector2& GetFinalPos() const;
		const Math::Vector2& GetSize() const;
		Gdiplus::Rect GetFinalRectInMYC() const;

		uint32_t GetUniqueNumber() const { return m_ObjectUniqueNumber; }
		Collider* GetCollider() const { return m_Collider; }

		virtual void EnterCollision(GameObject* obj);
		virtual void OnCollision(GameObject* obj);
		virtual void ExitCollision(GameObject* obj);

	protected:
		TransformComponent* m_TransformComponent;
		RenderComponent* m_RenderComponent;

		Collider* m_Collider;

		uint32_t m_ObjectUniqueNumber;
	};

}


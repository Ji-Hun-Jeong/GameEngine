#pragma once
#include "Component.h"
namespace Game
{
	using namespace Math;
	class RigidBody : public Component
	{
	public:
		RigidBody(GameObject* owner);
		RigidBody(const RigidBody& other);
		virtual ~RigidBody();

	public:
		virtual void Update(float dt) = 0;

		void SetForce(const Vector2& force) { m_Force = force; }
		void AddForce(const Vector2& force) { m_Force += force; }

		void SetAccel(const Vector2& accel) { m_Accel = accel; }
		void AddtAccel(const Vector2& accel) { m_Accel += accel; }

		void SetVelocity(const Vector2& velocity) { m_Velocity = velocity; }
		void AddVelocity(const Vector2& velocity) { m_Velocity += velocity; }

		void SetCoeff(const Vector2& coeff) { m_Coeff = coeff; }
		void AddCoeff(const Vector2& coeff) { m_Coeff += coeff; }

		void OnGround(bool onGround);

		const Vector2& GetForce() const { return m_Force; }
		const Vector2& GetActionForce() const { return m_ActionForce; }
		const Vector2& GetAccel() const { return m_Accel; }
		const Vector2& GetVelocity() const  { return m_Velocity; }
		const Vector2& GetCoeff() const  { return m_Coeff; }
		bool IsOnGround() const { return m_Ground; }

	protected:
		Vector2 m_Force;
		Vector2 m_ActionForce;
		Vector2 m_Accel;
		Vector2 m_Velocity;
		Vector2 m_Coeff;	// 얘도 뭔가 다른얘가 들고있는게?

		float m_MaxSpeed;
		float m_Mass;
		float m_Gravity;	// 이건 나중에 게임 전체적인 클래스로 만드는게..?

		bool m_Ground;
	};
}



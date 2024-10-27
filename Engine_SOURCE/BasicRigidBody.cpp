#include "BasicRigidBody.h"
#include "TransformComponent.h"
#include "GameObject.h"

namespace Game
{
	BasicRigidBody::BasicRigidBody()
		: RigidBody()
	{
	}
	BasicRigidBody::~BasicRigidBody()
	{
	}
	void BasicRigidBody::Update(float dt)
	{
		TransformComponent* const ownerTransform = m_Owner->GetComponent<TransformComponent*>("Transform");

		Vector2 ownerPos = ownerTransform->GetPos();

		m_Force.y += m_Gravity * m_Mass;

		m_Accel = m_Force / m_Mass;	// 가속도

		m_Velocity += m_Accel * dt;

		// 반작용
		if (0 < m_Velocity.Length())
			m_Velocity += -(m_Velocity).Normalize() * m_Coeff * dt;

		// 힘의 크기 체크
		const Vector2 absVelocity = m_Velocity.Abs();

		if (absVelocity.x < 0.1f)
			m_Velocity.x = 0.0f;

		if (absVelocity.y < 0.1f)
			m_Velocity.y = 0.0f;

		if (m_MaxSpeed < absVelocity.x)
			m_Velocity.x = m_Velocity.x < 0 ? -m_MaxSpeed : m_MaxSpeed;
		if (m_MaxSpeed < absVelocity.y)
			m_Velocity.y = m_Velocity.y < 0 ? -m_MaxSpeed : m_MaxSpeed;

		ownerPos += m_Velocity * dt;
		ownerTransform->SetPos(ownerPos);

		m_ActionForce = m_Force;
		m_Force = Vector2();
	}
}

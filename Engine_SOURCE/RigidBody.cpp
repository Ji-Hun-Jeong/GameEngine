#include "RigidBody.h"

namespace Game
{
	RigidBody::RigidBody(GameObject* owner)
		: Component(owner, "RigidBody")
		, m_Coeff(Vector2(700.0f, 10.0f))
		, m_MaxSpeed(350.0f)
		, m_Mass(1.0f)
		, m_Gravity(800.0f)
		, m_Ground(false)
	{
	}
	RigidBody::RigidBody(const RigidBody& other)
		: Component(other)
		, m_MaxSpeed(other.m_MaxSpeed)
		, m_Mass(other.m_Mass)
		, m_Gravity(other.m_Gravity)
		, m_Ground(other.m_Ground)
	{
	}
	RigidBody::~RigidBody()
	{
	}
	void RigidBody::OnGround(bool onGround)
	{
		if (onGround)
		{
			m_Velocity.y = 0.0f;
			m_Ground = true;
		}
		else
			m_Ground = false;
	}
}

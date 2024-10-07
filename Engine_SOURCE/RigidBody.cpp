#include "RigidBody.h"

namespace Game
{
	RigidBody::RigidBody()
		: Component("RigidBody")
		, m_Coeff(Vector2(700.0f, 10.0f))
		, m_MaxSpeed(350.0f)
		, m_Mass(1.0f)
		, m_Gravity(800.0f)
		, m_Ground(false)
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

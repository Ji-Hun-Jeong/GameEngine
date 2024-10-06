#include "RigidBody.h"

namespace Game
{
	RigidBody::RigidBody(GameObject* owner)
		: Component(owner, "RigidBody")
		, m_Coeff(Vector2(1000.0f, 10.0f))
		, m_MaxSpeed(350.0f)
		, m_Mass(1.0f)
		, m_Gravity(800.0f)
	{
	}
	RigidBody::RigidBody(const RigidBody& other)
		: Component(other)
		, m_MaxSpeed(other.m_MaxSpeed)
		, m_Mass(other.m_Mass)
		, m_Gravity(other.m_Gravity)
	{
	}
	RigidBody::~RigidBody()
	{
	}
}

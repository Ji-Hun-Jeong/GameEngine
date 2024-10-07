#pragma once
#include "RigidBody.h"
namespace Game
{
	class BasicRigidBody : public RigidBody
	{
		CLONE(RigidBody, BasicRigidBody)
	public:
		BasicRigidBody();
		BasicRigidBody(const BasicRigidBody&) = default;
		~BasicRigidBody();

	public:
		void Update(float dt) override;

	};
}



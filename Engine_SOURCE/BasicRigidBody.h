#pragma once
#include "RigidBody.h"
namespace Game
{
	class BasicRigidBody : public RigidBody
	{
	public:
		BasicRigidBody(GameObject* owner);
		BasicRigidBody(const BasicRigidBody& other);
		~BasicRigidBody();

	public:
		void Update(float dt) override;

	};
}



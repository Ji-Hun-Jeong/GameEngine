#include "PlayerCollider.h"
#include "BackGroundCollider.h"
#include "MonsterCollider.h"
#include "TransformComponent.h"
#include "CollisionMgr.h"
#include "TimeMgr.h"
#include "RigidBody.h"

namespace Game
{
	PlayerCollider::PlayerCollider(UINT numOfCollider)
		: Collider(numOfCollider)
	{
	}
	PlayerCollider::~PlayerCollider()
	{
	}


	void PlayerCollider::EnterCollision(const BackGroundCollider* const collider)
	{
		cout << "Enter Player <- BackGroundCollider\n";
	}
	void PlayerCollider::OnCollision(const BackGroundCollider* const collider)
	{
		cout << "On Player <- BackGroundCollider\n";
	}
	void PlayerCollider::ExitCollision(const BackGroundCollider* const collider)
	{
		cout << "Exit Player <- BackGroundCollider\n";
	}


	void PlayerCollider::EnterCollision(const MonsterCollider* const collider)
	{
		//cout << "Enter Player <- MonsterCollider\n";
	}
	void PlayerCollider::OnCollision(const MonsterCollider* const collider)
	{
		//cout << "On Player <- MonsterCollider\n";
		const Math::Vector2& monsterColliderPos = collider->GetColliderPos();
		const Math::Vector2& monsterColliderSize = collider->GetColliderSize();
		TransformComponent* const ownerTransform = m_Owner->GetComponent<TransformComponent*>("Transform");

		const float dt = TimeMgr::GetInst().DeltaTime() * 1000.0f;
		const float groundY = monsterColliderPos.y - monsterColliderSize.y / 2.0f + dt;
		const float playerFoot = ownerTransform->GetPos().y + ownerTransform->GetSize().y / 2.0f;
		Math::Vector2 ownerPos = ownerTransform->GetPos();

		RigidBody* const rigidBody = m_Owner->GetComponent<RigidBody*>("RigidBody");
		rigidBody->SetCoeff(Vector2(1000.0f, 10.0f));

		if (groundY > playerFoot)
		{
			rigidBody->OnGround(true);
			ownerPos.y = monsterColliderPos.y - monsterColliderSize.y;
		}
		ownerTransform->SetPos(ownerPos);
	}
	void PlayerCollider::ExitCollision(const MonsterCollider* const collider)
	{
		RigidBody* const rigidBody = m_Owner->GetComponent<RigidBody*>("RigidBody");
		Vector2 c = rigidBody->GetCoeff();
		rigidBody->SetCoeff(Vector2(700.0f, 10.0f));
		rigidBody->OnGround(false);
		//cout << "Exit Player <- MonsterCollider\n";
	}
}

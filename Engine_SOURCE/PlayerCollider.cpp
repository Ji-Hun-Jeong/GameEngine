#include "PlayerCollider.h"
#include "BackGroundCollider.h"
#include "MonsterCollider.h"
#include "TransformComponent.h"
#include "CollisionMgr.h"
#include "TimeMgr.h"

namespace Game
{
	PlayerCollider::PlayerCollider(GameObject* owner, UINT numOfCollider)
		: Collider(owner, numOfCollider)
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
		cout << "Enter Player <- MonsterCollider\n";
	}
	void PlayerCollider::OnCollision(const MonsterCollider* const collider)
	{
		cout << "On Player <- MonsterCollider\n";
		const Math::Vector2& monsterColliderPos = collider->GetColliderPos();
		const Math::Vector2& monsterColliderSize = collider->GetColliderSize();
		TransformComponent* ownerTransform = m_Owner->GetComponent<TransformComponent*>("Transform");

		const Math::Vector2 distVector = ownerTransform->GetPos() - monsterColliderPos;

		ownerTransform->SetPos(monsterColliderPos + distVector * 1.01f);

		// gameobject와 collider의 충돌검사임 주의할 것
		if (CollisionMgr::CheckBoxCollision(ownerTransform->GetPos(), ownerTransform->GetSize()
			, monsterColliderPos, monsterColliderSize) == false)
			return;

		OnCollision(collider);
	}
	void PlayerCollider::ExitCollision(const MonsterCollider* const collider)
	{
		cout << "Exit Player <- MonsterCollider\n";
	}
}

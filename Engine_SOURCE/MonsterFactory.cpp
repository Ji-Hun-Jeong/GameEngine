#include "MonsterFactory.h"
#include "Monster.h"
#include "Animator.h"
#include "MonsterCollider.h"
#include "BackGroundTransform.h"

namespace Game
{
	GameObject* MonsterFactory::CreateObject(const Math::Vector2& pos, const Math::Vector2& size)
	{
		Monster* monster = new Monster;

		BackGroundTransform* transform = new BackGroundTransform(monster, Math::Vector2(), Math::Vector2());
		monster->SetTransformComponent(transform);

		monster->SetPos(pos);
		monster->SetSize(size);

		/*Animator* animator = new Animator(monster);
		monster->SetRenderComponent(animator);
		monster->SetTexture("PlayerTexture");*/

		MonsterCollider* collider = new MonsterCollider(monster, 0);
		monster->AddCollider(collider);
		return monster;
	}
}
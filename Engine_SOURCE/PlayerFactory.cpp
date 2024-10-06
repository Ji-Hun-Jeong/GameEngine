#include "PlayerFactory.h"
#include "Player.h"
#include "PlayerCollider.h"
#include "PlayerMove.h"
#include "PlayerTransform.h"
#include "BasicRigidBody.h"
#include "Animator.h"

namespace Game
{
	GameObject* PlayerFactory::CreateObject(const Math::Vector2& pos, const Math::Vector2& size)
	{
		Player* player = new Player;

		PlayerTransform* playerTransform = new PlayerTransform(player, Math::Vector2(), Math::Vector2());
		player->SetTransformComponent(playerTransform);

		player->SetPos(pos);
		player->SetSize(size);

		MoveComponent* move = new PlayerMove(player);
		player->SetMoveComponent(move);

		RigidBody* rigidBody = new BasicRigidBody(player);
		player->SetRigidBody(rigidBody);

		Animator* animator = new Animator(player, 0.1f);
		animator->AddTextureCutInfoByFile("Animation/PlayerWalk.txt");
		player->SetRenderComponent(animator);
		player->SetTexture("PlayerTexture");

		Collider* collider = new PlayerCollider(player, 0);
		player->AddCollider(collider);

		return player;
	}
}


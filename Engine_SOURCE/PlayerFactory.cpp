#include "PlayerFactory.h"
#include "Player.h"
#include "PlayerCollider.h"
#include "PlayerMove.h"
#include "PlayerTransform.h"
#include "BasicRigidBody.h"
#include "StateController.h"
#include "Animator.h"
#include "IdleState.h"
#include "JumpState.h"
#include "WalkState.h"
#include "Animation.h"

namespace Game
{
	GameObject* PlayerFactory::CreateObject(const Math::Vector2& pos, const Math::Vector2& size)
	{
		Player* player = new Player;

		PlayerTransform* playerTransform = new PlayerTransform(Math::Vector2(), Math::Vector2());
		player->SetTransformComponent(playerTransform);

		player->SetPos(pos);
		player->SetSize(size);

		MoveComponent* move = new PlayerMove;
		player->SetMoveComponent(move);

		RigidBody* rigidBody = new BasicRigidBody;
		player->SetRigidBody(rigidBody);

		StateController* stateController = new StateController;
		player->SetStateController(stateController);

		Animator* animator = new Animator;
		player->SetRenderComponent(animator);

		State* state = new IdleState(stateController);
		Animation* animation = new Animation(state->GetName(), 0.1f);
		animation->SetTexture("PlayerTexture");
		animation->AddTextureCutInfoByFile("Animation/PlayerIdle1.txt");
		animator->AddAnimation(animation);
		stateController->AddState(state);

		state = new JumpState(stateController);
		animation = new Animation(state->GetName(), 0.2f);
		animation->SetTexture("PlayerTexture");
		animation->AddTextureCutInfoByFile("Animation/PlayerJump.txt");
		animator->AddAnimation(animation);
		stateController->AddState(state);

		state = new WalkState(stateController);
		animation = new Animation(state->GetName(), 0.1f);
		animation->SetTexture("PlayerTexture");
		animation->AddTextureCutInfoByFile("Animation/PlayerWalk.txt");
		animator->AddAnimation(animation);
		stateController->AddState(state);

		stateController->ChangeState("Idle");

		Collider* collider = new PlayerCollider(0);
		player->AddCollider(collider);
		
		return player;
	}
}


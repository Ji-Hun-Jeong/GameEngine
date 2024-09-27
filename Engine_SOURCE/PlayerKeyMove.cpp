#include "PlayerKeyMove.h"
#include "KeyMgr.h"
#include "GameObject.h"

Game::PlayerKeyMove::PlayerKeyMove()
	: Component("PlayerKeyMove")
{}

Game::PlayerKeyMove::~PlayerKeyMove()
{
}

void Game::PlayerKeyMove::DoSomething(GameObject* const owner)
{
	if (KeyMgr::GetInst().GetKeyState(eKeyType::D, eButtonState::Hold))
	{
		owner->m_X += 1 * 0.05f;
	}
	if (KeyMgr::GetInst().GetKeyState(eKeyType::A, eButtonState::Hold))
	{
		owner->m_X += -1 * 0.05f;
	}
	if (KeyMgr::GetInst().GetKeyState(eKeyType::W, eButtonState::Hold))
	{
		owner->m_Y += -1 * 0.05f;
	}
	if (KeyMgr::GetInst().GetKeyState(eKeyType::S, eButtonState::Hold))
	{
		owner->m_Y += 1 * 0.05f;
	}
}

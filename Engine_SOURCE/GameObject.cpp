#include "GameObject.h"

namespace Game
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
	}
	void GameObject::Render(HDC dc)
	{
		Rectangle(dc, 100, 100, 200, 200);
	}
}

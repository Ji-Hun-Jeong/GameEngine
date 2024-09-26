#pragma once
#include "Common.h"
namespace Game
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	public:
		void Update();
		void Render(HDC dc);
	};
}


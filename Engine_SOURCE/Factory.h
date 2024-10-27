#pragma once
#include "Common.h"

namespace Game
{
	class Factory
	{
	public:
		Factory() = default;
		virtual ~Factory() = default;

	public:
		virtual class GameObject* CreateObject(class GameObject* obj
			, const Math::Vector2& pos = Math::Vector2()
			, const Math::Vector2& size = Math::Vector2()) = 0;

	};
}



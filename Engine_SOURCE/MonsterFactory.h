#pragma once
#include "Factory.h"
namespace Game
{
	class MonsterFactory : public Factory
	{
    public:
        MonsterFactory() = default;
        ~MonsterFactory() = default;

    public:
        GameObject* CreateObject(const Math::Vector2& pos = Math::Vector2()
            , const Math::Vector2& size = Math::Vector2()) override;
	};
}



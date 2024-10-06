#pragma once
#include "Factory.h"
namespace Game
{
    class PlayerFactory : public Factory
    {
    public:
        PlayerFactory() = default;
        ~PlayerFactory() = default;

    public:
        GameObject* CreateObject(const Math::Vector2& pos = Math::Vector2()
            , const Math::Vector2& size = Math::Vector2()) override;
    };

}


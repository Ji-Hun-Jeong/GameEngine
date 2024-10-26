#pragma once
#include "Factory.h"
namespace Game
{
	class UIFactory : public Factory
	{
    public:
        UIFactory() = default;
        ~UIFactory() = default;

    public:
        GameObject* CreateObject(GameObject* obj, const Math::Vector2& pos = Math::Vector2()
            , const Math::Vector2& size = Math::Vector2()) override;
	};
}



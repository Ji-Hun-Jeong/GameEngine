#pragma once
#include "Factory.h"
namespace Game
{
	class CameraFactory : public Factory
	{
    public:
        CameraFactory() = default;
        ~CameraFactory() = default;

    public:
        GameObject* CreateObject(const Math::Vector2& pos = Math::Vector2()
            , const Math::Vector2& size = Math::Vector2()) override;
	};
}



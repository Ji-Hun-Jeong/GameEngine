#pragma once
#include "GameObject.h"
namespace Game
{
	class Component : public Entity
	{
	public:
		Component(const std::string& name);
		Component(const Component& other);
		virtual ~Component() = 0;

	public:
		static Gdiplus::Rect GetRectInMYC(const Math::Vector2& pos, const Math::Vector2& size);

	protected:

	};
}



#pragma once
#include "Entity.h"

namespace Game
{
	class Layout : public Entity
	{
	public:
		Layout(const std::string& name);
		Layout(const Layout& other);
		virtual ~Layout();

	public:
		virtual Layout* GetClone() const = 0;
		virtual bool PlaceUI(class UI* parent, class UI* child) = 0;

		static bool IsPossibleInParentUI(const Math::Vector2& parentSize, const Math::Vector2& childUISize
			, const Math::Vector2& childUIOffset);
	};
}


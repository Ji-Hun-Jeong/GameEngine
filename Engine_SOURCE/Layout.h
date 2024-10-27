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
		virtual void PlaceUI(class UI* parent, class UI* child) = 0;

	};
}


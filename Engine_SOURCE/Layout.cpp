#include "Layout.h"

namespace Game
{
	Layout::Layout(const std::string& name)
		: Entity(name)
	{
	}

	Layout::Layout(const Layout& other)
		: Entity(other)
	{
	}

	Layout::~Layout()
	{
	}
}


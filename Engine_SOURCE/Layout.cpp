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
	bool Layout::IsPossibleInParentUI(const Math::Vector2& parentSize, const Math::Vector2& childUISize
		, const Math::Vector2& childUIOffset)
	{
		float right = parentSize.x / 2.0f;
		float bottom = parentSize.y / 2.0f;

		if (right < childUIOffset.x + childUISize.x / 2.0f)
			return false;
		if (childUIOffset.x - childUISize.x / 2.0f < -right)
			return false;

		if (bottom < childUIOffset.y + childUISize.y / 2.0f)
			return false;
		if (childUIOffset.y - childUISize.y / 2.0f < -bottom)
			return false;

		return true;
	}
}


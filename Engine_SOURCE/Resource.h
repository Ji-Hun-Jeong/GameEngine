#pragma once
#include "Entity.h"
namespace Game
{
	class Resource : public Entity
	{
	public:
		Resource(const std::string& resourceName);
		virtual ~Resource();

	protected:

	};
}

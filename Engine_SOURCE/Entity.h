#pragma once
#include "Common.h"
namespace Game
{
	class Entity
	{
	public:
		Entity(const std::string& name);
		virtual ~Entity();

	public:
		const std::string& GetName() const { return m_StrName; }
		void SetName(const std::string& name) { m_StrName = name; }

	protected:
		std::string m_StrName;
	};
}


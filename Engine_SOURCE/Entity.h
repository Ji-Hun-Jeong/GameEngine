#pragma once
#include "Common.h"

namespace Game
{
	class Entity
	{
	public:
		Entity(const std::string& name);
		Entity(const Entity& other);
		virtual ~Entity() = 0;

	public:
		const std::string& GetName() const { return m_Name; }
		const std::wstring& GetNameW() const { return m_NameW; }

	protected:
		std::string m_Name;
		std::wstring m_NameW;
	};
}


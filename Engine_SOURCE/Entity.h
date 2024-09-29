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
		const std::string& GetName() const { return m_Name; }
		const std::wstring& GetNameW() const { return m_NameW; }

	protected:
		std::string m_Name;
		std::wstring m_NameW;
	};
}


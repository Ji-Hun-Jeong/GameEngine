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
		void SetName(const std::string& name) { m_Name = name; }

	protected:
		std::string m_Name;
	};
}


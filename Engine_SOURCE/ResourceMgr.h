#pragma once
#include "Common.h"
namespace Game
{
	enum class eResourceType
	{
		Texture,
		End,
	};
	class Resource;
	class ResourceMgr
	{
		SINGLE(ResourceMgr)
	public:
		void LoadResource(eResourceType resourceType, const std::string& resourceName
			, const std::string& fileName);
		[[nodiscard]] Resource* GetResource(eResourceType resourceType, const std::string& resourceName);

	private:
		std::map<std::string, Resource*> m_ArrResourcesMap[(UINT)eResourceType::End];
	};
}



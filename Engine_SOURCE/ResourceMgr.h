#pragma once
#include "Common.h"
namespace Game
{
	enum class eResourceType
	{
		Texture,
		End,
	};
	class ResourceMgr
	{
		SINGLE(ResourceMgr)
	public:
		void LoadResource(eResourceType resourceType, const std::string& resourceName
			, const std::string& fileName);
		[[nodiscard]] class Resource* GetResource(eResourceType resourceType, const std::string& resourceName);

	private:
		std::map<std::string, class Resource*> m_ArrResourcesMap[(UINT)eResourceType::End];
	};
}



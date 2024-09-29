#include "ResourceMgr.h"
#include "Texture.h"
namespace Game
{
	ResourceMgr::ResourceMgr()
	{

	}
	ResourceMgr::~ResourceMgr()
	{
		for (UINT i = 0; i < (UINT)eResourceType::End; ++i)
			Utility::DeleteMap<std::string, Resource*>(m_ArrResourcesMap[i]);
	}
	void ResourceMgr::LoadResource(eResourceType resourceType, const std::string& resourceName
	, const std::string& fileName)
	{
		Resource* resource = nullptr;

		std::map<std::string, Resource*>& map = m_ArrResourcesMap[(UINT)resourceType];
		auto iter = map.find(resourceName);
		if (iter != map.end())
			assert(0);

		if (resourceType == eResourceType::Texture)
			resource = new Texture(resourceName, fileName);
		
		map.insert(std::make_pair(resource->GetName(), resource));
		std::cout << "Load Resource : " + resourceName << '\n';
	}
	Resource* ResourceMgr::GetResource(eResourceType resourceType, const std::string& resourceName)
	{
		std::map<std::string, Resource*>& map = m_ArrResourcesMap[(UINT)resourceType];
		auto iter = map.find(resourceName);
		if (iter == map.end())
			assert(0);
		return iter->second;
	}
}

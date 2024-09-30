#include "RenderComponent.h"
#include "ResourceMgr.h"

namespace Game
{
	RenderComponent::RenderComponent(const std::string& name, GameObject* const owner)
		: Component(name, owner)
		, m_Texture(nullptr)
	{
	}
	RenderComponent::~RenderComponent()
	{
	}
	void RenderComponent::SetTexture(const std::string& textureName)
	{
		// 미리 전부 로딩을 해놓고 ResourceMgr에게 받아서 쓰는 것
		m_Texture = dynamic_cast<Texture*>(
			ResourceMgr::GetInst().GetResource(eResourceType::Texture, textureName));

		assert(m_Texture);
	}

}

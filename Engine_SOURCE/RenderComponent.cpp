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
		// �̸� ���� �ε��� �س��� ResourceMgr���� �޾Ƽ� ���� ��
		m_Texture = dynamic_cast<Texture*>(
			ResourceMgr::GetInst().GetResource(eResourceType::Texture, textureName));

		assert(m_Texture);
	}

}

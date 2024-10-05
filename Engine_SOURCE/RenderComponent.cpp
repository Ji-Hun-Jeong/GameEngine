#include "RenderComponent.h"
#include "ResourceMgr.h"

namespace Game
{
	RenderComponent::RenderComponent(GameObject* owner)
		: Component(owner, "Render")
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

	Math::Vector2 RenderComponent::GetTextureSize()
	{
		assert(m_Texture);
		return Math::Vector2(float(m_Texture->GetWidth()), float(m_Texture->GetHeight()));
	}

}

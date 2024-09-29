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
	RECT RenderComponent::GetRectangle(const Math::Vector2& pos, const Math::Vector2& size)
	{
		RECT result;
		result.left = static_cast<LONG>(pos.x - size.x / 2.0f);
		result.top = static_cast<LONG>(pos.y - size.y / 2.0f);
		result.right = static_cast<LONG>(pos.x + size.x / 2.0f);
		result.bottom = static_cast<LONG>(pos.y + size.y / 2.0f);
		return result;
	}
}

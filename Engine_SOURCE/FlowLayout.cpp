#include "FlowLayout.h"
#include "UI.h"

namespace Game
{
	FlowLayout::FlowLayout()
		: FlowLayout(0, 0)
	{
	}

	FlowLayout::FlowLayout(UINT widthGap, UINT heightGap)
		: Layout("Flow")
		, m_WidthGap(widthGap)
		, m_HeightGap(heightGap)
	{
	}

	FlowLayout::FlowLayout(const FlowLayout& other)
		: Layout(other)
		, m_WidthGap(other.m_WidthGap)
		, m_HeightGap(other.m_HeightGap)
	{
	}

	FlowLayout::~FlowLayout()
	{
	}

	bool FlowLayout::PlaceUI(UI* const parentUI, UI* const attachUI)
	{
		const std::vector<UI*>& childVec = parentUI->GetChildUI();
		const Math::Vector2& parentPos = parentUI->GetFinalPos();
		const Math::Vector2& parentSize = parentUI->GetSize();

		const Math::Vector2& attachUISize = attachUI->GetSize();

		float right = parentSize.x / 2.0f;
		float bottom = parentSize.y / 2.0f;

		const Math::Vector2& firstOffset = -parentSize / 2.0f + attachUISize / 2.0f;
		Math::Vector2 finalOffset;
		if (childVec.size())
		{
			const UI* lastChild = nullptr;
			lastChild = childVec.back();
			finalOffset = lastChild->GetOffset();
			finalOffset.x += lastChild->GetSize().x / 2.0f + attachUISize.x / 2.0f;

			if (right < finalOffset.x + attachUISize.x / 2.0f)
			{
				finalOffset.x = firstOffset.x;
				finalOffset.y += lastChild->GetSize().y / 2.0f + attachUISize.y / 2.0f;

				if (bottom < finalOffset.y + attachUISize.y / 2.0f)
					return false;
			}
		}
		else
			finalOffset = firstOffset;

		attachUI->SetPos(parentPos);
		attachUI->SetOffset(finalOffset);
	}
}


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

	void FlowLayout::PlaceUI(UI* const parentUI, UI* const attachUI)
	{
		const std::vector<UI*>& childVec = parentUI->GetChildUI();
		const Math::Vector2& parentPos = parentUI->GetFinalPos();
		const Math::Vector2& parentSize = parentUI->GetSize();

		attachUI->SetPos(parentPos);
		const Math::Vector2& attachUISize = attachUI->GetSize();

		const UI* lastChild = nullptr;
		Math::Vector2 lastOffset;
		if (childVec.size())
		{
			lastChild = childVec.back();
			lastOffset = lastChild->GetOffset();

			//lastOffset.x += attachUISize.x;
		}
		else
			lastOffset = -parentSize/2.0f + attachUISize/2.0f;

		attachUI->SetOffset(lastOffset);
	}
}


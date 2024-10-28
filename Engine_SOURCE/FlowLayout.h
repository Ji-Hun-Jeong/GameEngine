#pragma once
#include "Layout.h"
namespace Game
{
	class FlowLayout : public Layout
	{
		CLONE(Layout, FlowLayout)
	public:
		FlowLayout();
		FlowLayout(UINT widthGap, UINT heightGap);
		FlowLayout(const FlowLayout& other);
		~FlowLayout();

	public:
		bool PlaceUI(class UI* const parentUI, class UI* const attachUI) override;

	private:
		UINT m_WidthGap;
		UINT m_HeightGap;
	};
}



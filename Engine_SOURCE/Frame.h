#pragma once
#include "GameObject.h"
namespace Game
{
	class Frame : public GameObject
	{
	public:
		explicit Frame(const std::string& name, UINT numOfFrame, const Gdiplus::Rect& rect);
		~Frame();

	private:

	};
}



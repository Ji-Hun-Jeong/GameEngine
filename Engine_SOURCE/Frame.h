#pragma once
#include "GameObject.h"
namespace Game
{
	class Frame : public GameObject
	{
		CLONE(GameObject, Frame)
	public:
		explicit Frame(const std::string& name, UINT numOfFrame, const Gdiplus::Rect& rect);
		Frame(const Frame& other);
		~Frame();

	private:

	};
}



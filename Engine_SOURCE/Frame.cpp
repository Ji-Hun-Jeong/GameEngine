#include "Frame.h"
#include "FrameTransform.h"
#include "BasicRenderer.h"

namespace Game
{
	Frame::Frame(const std::string& name, UINT numOfFrame, const Gdiplus::Rect& rect)
		: GameObject(name + std::to_string(numOfFrame))
	{
		SetTransformComponent(new FrameTransform(Math::Vector2(float(rect.X), float(rect.Y))
			, Math::Vector2(float(rect.Width), float(rect.Height))));
		SetRenderComponent(new BasicRenderer);
	}
	Frame::~Frame()
	{
	}
}
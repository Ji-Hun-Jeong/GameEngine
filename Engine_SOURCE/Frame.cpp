#include "Frame.h"
#include "FrameTransform.h"
#include "BasicRenderer.h"

namespace Game
{
	Frame::Frame(const std::string& name, UINT numOfFrame, const Gdiplus::Rect& rect)
		: GameObject(name + std::to_string(numOfFrame))
	{
		SetTransformComponent(new FrameTransform(this
			, Math::Vector2(rect.X, rect.Y), Math::Vector2(rect.Width, rect.Height)));
		SetRenderComponent(new BasicRenderer(this));
	}
	Frame::~Frame()
	{
	}
}
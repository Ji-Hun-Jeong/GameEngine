#include "UIFactory.h"
#include "UI.h"
#include "StaticTransform.h"
#include "BasicRenderer.h"
#include "BackGroundTransform.h"

namespace Game
{
	GameObject* UIFactory::CreateObject(const Math::Vector2& pos, const Math::Vector2& size)
	{
		UI* ui = new UI;

		BackGroundTransform* transform = new BackGroundTransform(pos, size);
		ui->SetTransformComponent(transform);

		BasicRenderer* renderer = new BasicRenderer;
		ui->SetRenderComponent(renderer);

		return ui;
	}
}


#include "UIFactory.h"
#include "UI.h"
#include "StaticTransform.h"
#include "BasicRenderer.h"
#include "UIMove.h"
#include "MainUI.h"

namespace Game
{
	GameObject* UIFactory::CreateObject(GameObject* obj, const Math::Vector2& pos, const Math::Vector2& size)
	{
		UI* ui = dynamic_cast<UI*>(obj);
		assert(ui);

		StaticTransform* transform = new StaticTransform(pos, size);
		ui->SetTransformComponent(transform);

		BasicRenderer* renderer = new BasicRenderer;
		ui->SetRenderComponent(renderer);

		UIMove* moveComponent = new UIMove;
		ui->SetMoveComponent(moveComponent);

		return ui;
	}
}


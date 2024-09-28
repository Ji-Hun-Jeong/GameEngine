#pragma once
#include "TransformComponent.h"
namespace Game
{
	class PlayerTransform : public TransformComponent
	{
	public:
		explicit PlayerTransform(GameObject* const owner);
		~PlayerTransform();
		
	public:
		void Update() override;

	private:

	};
}



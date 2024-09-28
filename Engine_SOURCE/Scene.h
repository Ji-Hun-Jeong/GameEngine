#pragma once
#include "Entity.h"
#include "GameObject.h"

namespace Game
{
	class Scene : public Entity
	{
	public:
		Scene(const std::string& name);
		virtual ~Scene() = 0;

	public:
		void Update(float dt);
		void PostUpdate(float dt);
		void Render(HDC dc);
		void AddGameObject(GameObject* const object);
		void DeleteGameObject(const std::string& objectName);

	protected:
		std::map<std::string, GameObject*> m_MapGameObjects;

	};
}



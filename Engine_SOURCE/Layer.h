#pragma once
#include "Entity.h"
namespace Game
{
	class GameObject;
	class Camera;
	enum class eLayerType
	{
		BackGround,
		Entity,
		Monster,
		Player,
		End = 16,
	};
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

	public:
		void Update(float dt);
		void PostUpdate(float dt, Camera* const curCamera);
		void Render(HDC dc);
		void AddGameObject(GameObject* const object);
		void DeleteGameObject(const std::string& objectName);

		std::map< std::string, GameObject*>& GetGameObjects() { return m_MapGameObjects; }

	private:
		std::map<std::string, GameObject*> m_MapGameObjects;
	};
}



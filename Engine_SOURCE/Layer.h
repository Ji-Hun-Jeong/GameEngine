#pragma once
#include "Entity.h"
namespace Game
{
	enum class eLayerType
	{
		BackGround,
		Entity,
		Monster,
		Player,
		UI,
		End = 16,
	};
	class Layer : public Entity
	{
	public:
		Layer();
		Layer(const Layer& other) = delete;
		~Layer();

	public:
		void Update(float dt);
		void PostUpdate(float dt, class Camera* const curCamera);
		void Render(HDC dc);
		void AddGameObject(class GameObject* const object);
		void DeleteGameObject(const std::string& objectName);

		std::map< std::string, class GameObject*>& GetGameObjects() { return m_MapGameObjects; }

	private:
		// 일단 요소 별로 없으니까 map으로 하고 나중에 요소가 많아질 것 같다 싶으면 unordered_map으로 바꾸자
		// 아니근데 해시충돌도 그만큼 많이 일어날텐데 그냥 map이 낫지않나... 일단 나중에 다시 생각합시다
		std::map<std::string, class GameObject*> m_MapGameObjects;
	};
}



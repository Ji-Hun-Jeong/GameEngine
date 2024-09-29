#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "KeyMgr.h"
#include "MouseMgr.h"
#include "SceneMgr.h"
#include "Bitmap.h"

namespace Game
{
	class Scene : public Entity
	{
	public:
		Scene(const std::string& name, UINT width, UINT height);
		virtual ~Scene() = 0;

	public:
		virtual void EnterScene() = 0;
		virtual void ExitScene() = 0;
		virtual void DetectSceneEvent() = 0;

		void Update(float dt);
		void PostUpdate(float dt);
		void Render(HDC dc);
		void AddGameObject(GameObject* const object);
		void DeleteGameObject(const std::string& objectName);

	protected:
		std::map<std::string, GameObject*> m_MapGameObjects;
		Bitmap m_BitmapSet;
	};
}



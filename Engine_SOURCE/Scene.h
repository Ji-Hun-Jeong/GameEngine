#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "KeyMgr.h"
#include "MouseMgr.h"
#include "SceneMgr.h"
#include "Bitmap.h"
#include "Camera.h"

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
		void AddCamera(Camera* const camera);
		void DeleteGameObject(const std::string& objectName);
		void SetCurCamera(const std::string& cameraName);

	protected:
		std::map<std::string, GameObject*> m_MapGameObjects;
		std::vector<Camera*> m_VecCameras;
		Camera* m_CurCamera;
		Bitmap m_BitmapSet;
	};
}



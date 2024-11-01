#pragma once
#include <memory>

#include "BackGround.h"
#include "Bitmap.h"
#include "Camera.h"
#include "GameObject.h"
#include "KeyMgr.h"
#include "MouseMgr.h"
#include "SceneMgr.h"
#include "Layer.h"

namespace Game
{
	class Scene : public Entity
	{
	public:
		Scene(const std::string& name, UINT width, UINT height);
		Scene(const Scene&) = delete;
		virtual ~Scene();

	public:
		virtual void EnterScene() = 0;
		virtual void ExitScene() = 0;
		virtual void DetectSceneEvent() = 0;

		virtual void Update(float dt);
		virtual void PostUpdate(float dt);
		virtual void Render(HDC dc);

		void AddGameObject(eLayerType layerType, GameObject* const object);
		void AddCamera(Camera* const camera);
		void DeleteGameObject(eLayerType layerType, const std::string& objectName);

		void SetCurCamera(const std::string& cameraName);
		void SetCurCamera(Camera* const camera);

		std::map<std::string, GameObject*>& GetGameObject(eLayerType layer) 
		{ return m_ArrLayers[(UINT)layer].GetGameObjects(); }

	protected:
		std::array<Layer, (size_t)eLayerType::End> m_ArrLayers;
		std::vector<Camera*> m_VecCameras;
		Camera* m_CurCamera;
		Bitmap m_BitmapSet;
	};
}



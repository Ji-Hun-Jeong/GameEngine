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
		// �ϴ� ��� ���� �����ϱ� map���� �ϰ� ���߿� ��Ұ� ������ �� ���� ������ unordered_map���� �ٲ���
		// �ƴϱٵ� �ؽ��浹�� �׸�ŭ ���� �Ͼ�ٵ� �׳� map�� �����ʳ�... �ϴ� ���߿� �ٽ� �����սô�
		std::map<std::string, class GameObject*> m_MapGameObjects;
	};
}



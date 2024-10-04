#pragma once
#include "Common.h"
#include "Layer.h"
union CollisionKey
{
	struct
	{
		uint32_t upBit;
		uint32_t downBit;
	};
	uint64_t key;
};
namespace Game
{
	class Scene;
	class CollisionMgr
	{
		SINGLE(CollisionMgr)
	public:
		void Update();
		void CheckInCollisionMatrix(eLayerType left, eLayerType right, bool trueOrFalse);

	private:
		void checkTwoGroupCollision(Scene* const scene, eLayerType left, eLayerType right);
		bool checkCollision(GameObject* obj1, GameObject* obj2);

	private:
		std::bitset<(size_t)eLayerType::End> m_CollisionCheckMatrix[(size_t)eLayerType::End];
		std::map<uint64_t, std::pair<GameObject*, GameObject*>> m_MapCollisionObjects;
	};
}

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
	class Collider;
	class CollisionMgr
	{
		SINGLE(CollisionMgr)
	public:
		void Update();
		void CheckInCollisionMatrix(eLayerType left, eLayerType right, bool trueOrFalse);

	private:
		void checkTwoGroupObjectsCollision(Scene* const scene, eLayerType left, eLayerType right);
		void checkTwoObjectCollidersCollision(GameObject* obj1, GameObject* obj2);
		bool checkCollidersCollision(Collider* collider1, Collider* collider2);

	private:
		std::bitset<(size_t)eLayerType::End> m_CollisionCheckMatrix[(size_t)eLayerType::End];
		std::map<uint64_t, std::pair<Collider*, Collider*>> m_MapCollisionObjects;
	};
}

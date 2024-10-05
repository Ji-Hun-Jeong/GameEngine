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
		static bool CheckCollidersCollision(const Collider* const collider1, const Collider* const collider2);
		static bool CheckBoxCollision(const Math::Vector2& pos1, const Math::Vector2& size1
			, const Math::Vector2& pos2, const Math::Vector2& size2);

	private:
		void checkTwoGroupObjectsCollision(Scene* const scene, eLayerType left, eLayerType right);
		void checkTwoObjectCollidersCollision(GameObject* obj1, GameObject* obj2);


	private:
		std::bitset<(size_t)eLayerType::End> m_CollisionCheckMatrix[(size_t)eLayerType::End];
		std::set<uint64_t> m_MapCollisionObjectsState;
	};
}

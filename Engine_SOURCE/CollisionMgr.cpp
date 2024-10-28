#include "CollisionMgr.h"
#include "GameObject.h"
#include "Scene.h"
#include "Collider.h"

namespace Game
{
	CollisionMgr::CollisionMgr()
	{

	}
	CollisionMgr::~CollisionMgr()
	{
		
	}
	void CollisionMgr::Update()
	{
		Scene* curScene = SceneMgr::GetInst().GetCurScene();
		for (UINT i = 0; i < (UINT)eLayerType::End; ++i)
		{
			for (UINT j = 0; j < (UINT)eLayerType::End; ++j)
			{
				if (m_CollisionCheckMatrix[i][j] == false)
					continue;
				checkTwoGroupObjectsCollision(curScene, eLayerType(i), eLayerType(j));
			}
		}
	}

	void CollisionMgr::checkTwoGroupObjectsCollision(Scene* const scene, eLayerType left, eLayerType right)
	{
		std::map<std::string, GameObject*>& mapObj1 = scene->GetGameObject(left);
		std::map<std::string, GameObject*>& mapObj2 = scene->GetGameObject(right);

		GameObject* obj1 = nullptr;
		GameObject* obj2 = nullptr;

		for (auto iter1 = mapObj1.begin(); iter1 != mapObj1.end(); ++iter1)
		{
			obj1 = iter1->second;
			for (auto iter2 = mapObj2.begin(); iter2 != mapObj2.end(); ++iter2)
			{
				obj2 = iter2->second;
				checkTwoObjectCollidersCollision(obj1, obj2);
			}
		}
	}

	void CollisionMgr::checkTwoObjectCollidersCollision(GameObject* obj1, GameObject* obj2)
	{
		std::vector<Collider*>& vecColliders1 = obj1->GetColliders();
		std::vector<Collider*>& vecColliders2 = obj2->GetColliders();

		CollisionKey unionKey;
		Collider* collider1 = nullptr;
		Collider* collider2 = nullptr;

		for (size_t i = 0; i < vecColliders1.size(); ++i)
		{
			collider1 = vecColliders1[i];
			for (size_t i = 0; i < vecColliders2.size(); ++i)
			{
				collider2 = vecColliders2[i];
				assert(collider1 && collider2);

				unionKey.upBit = collider1->GetUniqueNumber();
				unionKey.downBit = collider2->GetUniqueNumber();

				auto iter = m_SetCollisionObjectsState.find(unionKey.key);

				bool isCollision = CheckCollidersCollision(collider1, collider2);
				if (isCollision)
				{
					if (iter == m_SetCollisionObjectsState.end())	// 이번프레임에 처음 충돌
					{
						m_SetCollisionObjectsState.insert(unionKey.key);

						collider1->EnterCollisionDeliverOther(collider2);
						collider2->EnterCollisionDeliverOther(collider1);
					}
					else										// 계속 충돌 중
					{
						collider1->OnCollisionDeliverOther(collider2);
						collider2->OnCollisionDeliverOther(collider1);
					}
				}
				else
				{
					if (iter != m_SetCollisionObjectsState.end())	// 충돌 끝
					{
						m_SetCollisionObjectsState.erase(unionKey.key);
						collider1->ExitCollisionDeliverOther(collider2);
						collider2->ExitCollisionDeliverOther(collider1);
					}
				}
			}
		}
	}

	bool CollisionMgr::CheckCollidersCollision(const Collider* const collider1, const Collider* const collider2)
	{
		if (collider1 == nullptr || collider2 == nullptr)
			return false;

		const Math::Vector2& collider1Pos = collider1->GetColliderPos();
		const Math::Vector2& collider1HalfSize = collider1->GetColliderSize() / 2.0f;
		const Math::Vector2& collider2Pos = collider2->GetColliderPos();
		const Math::Vector2& collider2HalfSize = collider2->GetColliderSize() / 2.0f;

		const float sumOfSizeX = collider1HalfSize.x + collider2HalfSize.x;
		const float sumOfSizeY = collider1HalfSize.y + collider2HalfSize.y;

		const Math::Vector2& vecOfBetweenColliders = collider1Pos - collider2Pos;

		const float distOfX = std::abs(vecOfBetweenColliders.x);
		const float distOfY = std::abs(vecOfBetweenColliders.y);

		if (distOfX <= sumOfSizeX && distOfY < sumOfSizeY)
			return true;
		return false;
	}

	bool CollisionMgr::CheckBoxCollision(const Math::Vector2& pos1, const Math::Vector2& size1
		, const Math::Vector2& pos2, const Math::Vector2& size2)
	{
		const Math::Vector2& halfSize1 = size1 / 2.0f;
		const Math::Vector2& halfSize2 = size2 / 2.0f;
		const float sumOfSizeX = halfSize1.x + halfSize2.x;
		const float sumOfSizeY = halfSize1.y + halfSize2.y;

		const Math::Vector2& vecOfBetweenPos = pos1 - pos2;

		const float distOfX = std::abs(vecOfBetweenPos.x);
		const float distOfY = std::abs(vecOfBetweenPos.y);

		if (distOfX <= sumOfSizeX && distOfY < sumOfSizeY)
			return true;
		return false;
	}

	void CollisionMgr::CheckInCollisionMatrix(eLayerType left, eLayerType right, bool trueOrFalse)
	{
		int row = int(left);
		int col = int(right);
		if (row > col)
		{
			row = int(right);
			col = int(left);
		}
		m_CollisionCheckMatrix[row][col] = trueOrFalse;
	}

}
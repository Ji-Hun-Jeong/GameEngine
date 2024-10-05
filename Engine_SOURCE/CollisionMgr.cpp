#include "CollisionMgr.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneMgr.h"
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

		for (Collider* collider1 : vecColliders1)
		{
			for (Collider* collider2 : vecColliders2)
			{
				unionKey.upBit = collider1->GetUniqueNumber();
				unionKey.downBit = collider2->GetUniqueNumber();

				auto iter = m_MapCollisionObjects.find(unionKey.key);

				bool isCollision = checkCollidersCollision(collider1, collider2);
				if (isCollision)
				{
					if (iter == m_MapCollisionObjects.end())	// 이번프레임에 처음 충돌
					{
						m_MapCollisionObjects.insert(std::make_pair(unionKey.key
							, std::make_pair(collider1, collider2)));

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
					if (iter != m_MapCollisionObjects.end())	// 충돌 끝
					{
						m_MapCollisionObjects.erase(unionKey.key);
						collider1->ExitCollisionDeliverOther(collider2);
						collider2->ExitCollisionDeliverOther(collider1);
					}
				}
			}
		}
	}

	bool CollisionMgr::checkCollidersCollision(Collider* collider1, Collider* collider2)
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

		const float distOfX = vecOfBetweenColliders.x;
		const float distOfY = vecOfBetweenColliders.y;

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
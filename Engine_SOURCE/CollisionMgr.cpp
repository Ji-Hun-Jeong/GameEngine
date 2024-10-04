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
				checkTwoGroupCollision(curScene, eLayerType(i), eLayerType(j));
			}
		}
	}

	void CollisionMgr::checkTwoGroupCollision(Scene* const scene, eLayerType left, eLayerType right)
	{
		std::map<std::string, GameObject*>& mapObj1 = scene->GetGameObject(left);
		std::map<std::string, GameObject*>& mapObj2 = scene->GetGameObject(right);

		GameObject* obj1 = nullptr;
		GameObject* obj2 = nullptr;

		CollisionKey unionKey;

		for (auto iter1 = mapObj1.begin(); iter1 != mapObj1.end(); ++iter1)
		{
			obj1 = iter1->second;
			for (auto iter2 = mapObj2.begin(); iter2 != mapObj2.end(); ++iter2)
			{
				obj2 = iter2->second;

				unionKey.upBit = obj1->GetUniqueNumber();
				unionKey.downBit = obj2->GetUniqueNumber();

				auto iter = m_MapCollisionObjects.find(unionKey.key);

				bool isCollision = checkCollision(obj1, obj2);
				if (isCollision)
				{
					if (iter == m_MapCollisionObjects.end())	// 이번프레임에 처음 충돌
					{
						m_MapCollisionObjects.insert(std::make_pair(unionKey.key
							, std::make_pair(obj1, obj2)));

						obj1->EnterCollision(obj2);
						obj2->EnterCollision(obj1);
					}
					else										// 계속 충돌 중
					{
						obj1->OnCollision(obj2);
						obj2->OnCollision(obj1);
					}
				}
				else
				{
					if (iter != m_MapCollisionObjects.end())	// 충돌 끝
					{
						m_MapCollisionObjects.erase(unionKey.key);
						obj1->ExitCollision(obj2);
						obj2->ExitCollision(obj1);
					}
				}
			}
		}
	}

	bool CollisionMgr::checkCollision(GameObject* obj1, GameObject* obj2)
	{
		const Collider* collider1 = obj1->GetCollider();
		const Collider* collider2 = obj2->GetCollider();
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
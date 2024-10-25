#pragma once

#include <Windows.h>
#include <assert.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <array>
#include <algorithm>

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")
#include <gdiplus.h>
#pragma comment(lib, "Gdiplus.lib")

#include "MyMath.h"
#include "Utility.h"

#define SINGLE(Type)	private:\
							Type();\
						public:\
							static Type& GetInst()\
							{\
								static Type inst;\
								return inst;\
							}\
							~Type();\
							Type(const Type&) = delete;\
							Type(Type&&) = delete;\
							Type& operator = (const Type&) = delete;

#define MAGENTA RGB(255,0,255)

#define COLLIDERDEFINE public:\
						void EnterCollisionDeliverOther(Collider* const otherCollider) const override\
						{otherCollider->EnterCollision(this);}\
						void OnCollisionDeliverOther(Collider* const otherCollider) const override\
						{otherCollider->OnCollision(this);}\
						void ExitCollisionDeliverOther(Collider* const otherCollider) const override\
						{otherCollider->ExitCollision(this);}

#define CLONE(Parent, Type) public:\
						Parent* GetClone() const {return new Type(*this);}

namespace Game
{
	enum class eButtonState
	{
		None,
		Tap,
		Hold,
		Released,
	};
}

using std::cout;
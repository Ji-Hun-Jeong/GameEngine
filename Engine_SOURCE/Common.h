#pragma once

#include <Windows.h>
#include <assert.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

//#include <gdiplus.h>
//#pragma comment(lib, "gdiplus")

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
							~Type();

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
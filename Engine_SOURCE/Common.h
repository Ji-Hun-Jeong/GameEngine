#pragma once

#include <Windows.h>
#include <assert.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
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
							~Type();
#define MAGENTA RGB(255,0,255)

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
#pragma once

#include <Windows.h>
#include <assert.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

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
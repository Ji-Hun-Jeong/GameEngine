#pragma once

#include <Windows.h>
#include <assert.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>

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
	namespace Utility
	{
		template <typename T>
		void SafeDeleteArr(T* arr, UINT arrSize)
		{
			for (UINT i = 0; i < arrSize; ++i)
			{
				if (arr[i])
					delete arr[i];
			}
		}
	}
	enum class eButtonState
	{
		None,
		Tap,
		Hold,
		Released,
	};
}
#pragma once

namespace Game
{
	namespace Utility
	{
		template <typename T>
		void DeleteArr(T* arr, UINT arrSize)
		{
			for (UINT i = 0; i < arrSize; ++i)
			{
				if (arr[i] == nullptr)
					assert(0);
				delete arr[i];
			}
		}
		template <typename T>
		void DeleteVector(std::vector<T>& vec)
		{
			for (size_t i = 0; i < vec.size(); ++i)
			{
				if (vec[i] == nullptr)
					assert(0);
				delete vec[i];
			}
			vec.clear();
		}
		template <typename T1, typename T2>
		void DeleteMap(std::map<T1, T2>& map)
		{
			for (auto iter = map.begin(); iter != map.end(); ++iter)
			{
				if (iter->second == nullptr)
					assert(0);
				delete iter->second;
			}
			map.clear();
		}
	}
}

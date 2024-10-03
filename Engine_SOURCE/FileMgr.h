#pragma once
#include "Common.h"
std::fstream& operator<<(std::fstream& ofs, const Gdiplus::Rect& rect);
namespace Game
{
	class FileMgr
	{
		SINGLE(FileMgr)
	public:
		std::fstream& OpenFile();
		void CloseFile();
		template <typename T>
		void SaveVector(const std::vector<T> vec)
		{
			std::string strWant;
			OpenFile();
			std::cout << "Want String : ";
			std::getline(std::cin, strWant);
			std::cout << '\n';

			m_FileStream << strWant << '\n';

			for (size_t i = 0; i < vec.size(); ++i)
			{
				m_FileStream << vec[i];
			}

			m_FileStream << "end\n";
			m_FileStream.close();

			std::cout << "Save Complete!\n\n";
		}

	private:
		std::fstream m_FileStream;
	};
}



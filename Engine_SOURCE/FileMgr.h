#pragma once
#include "Common.h"
#include "PathMgr.h"
std::fstream& operator<<(std::fstream& ofs, const Gdiplus::Rect& rect);
std::fstream& operator>>(std::fstream& ofs, Gdiplus::Rect& rect);
namespace Game
{
	class FileMgr
	{
		SINGLE(FileMgr)
	public:
		std::fstream& OpenFileForWrite();
		std::fstream& OpenFileForRead(const std::string& emptyOrFileName);

		template <typename T>
		void SaveToFileByVector(const std::vector<T>& vec);
		template <typename T>
		void SaveToVectorByFile(std::vector<T>& vec, const std::string& emptyOrFileName = "");

	private:
		std::fstream m_FileStream;
	};

	template<typename T>
	void FileMgr::SaveToFileByVector(const std::vector<T>& vec)
	{
		OpenFileForWrite();

		for (size_t i = 0; i < vec.size(); ++i)
		{
			m_FileStream << vec[i];
		}

		m_FileStream.close();

		std::cout << "Write Complete!\n\n";
	}
	template<typename T>
	void FileMgr::SaveToVectorByFile(std::vector<T>& vec, const std::string& fileName)
	{
		OpenFileForRead(fileName);

		T t;
		while (m_FileStream >> t)
		{
			vec.push_back(t);
		}

		m_FileStream.close();

		std::cout << "Read Complete!\n\n";
	}
}



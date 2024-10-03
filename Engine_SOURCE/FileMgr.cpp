#include "FileMgr.h"
#include "PathMgr.h"

std::fstream& operator<<(std::fstream& ofs, const Gdiplus::Rect& rect)
{
	ofs << rect.X << " " << rect.Y << " " << rect.Width << " " << rect.Height << "\n";
	return ofs;
}
namespace Game
{
	FileMgr::FileMgr()
	{

	}
	FileMgr::~FileMgr()
	{

	}
	std::fstream& FileMgr::OpenFile()
	{
		static std::string strFileMode = "OverWriteMode = 1, ContinueWriteMode = 8 : ";
		static UINT fileMode = 0;

		std::string abPath;
		abPath.reserve(50);

		std::string fileName;
		fileName.reserve(20);

		std::cout << "Input File Name : ";
		std::getline(std::cin, fileName);
		std::cout << '\n';
		while(true)
		{
			std::cout << strFileMode;
			std::cin >> fileMode;
			std::cin.ignore();
			if (fileMode == 1 || fileMode == 8)
				break;
			std::cout << "Mode Wrong\n\n";
		}

		abPath = std::move(PathMgr::GetInst().MakeAbsolutePath(fileName));
		m_FileStream.open(abPath, std::ios_base::out | fileMode);

		assert(m_FileStream.is_open());

		std::cout << "File Open Succees!\n\n";
		return m_FileStream;
	}
	void FileMgr::CloseFile()
	{
		assert(m_FileStream.is_open());
		m_FileStream.close();
	}
}
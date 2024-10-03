#include "FileMgr.h"

std::fstream& operator<<(std::fstream& ofs, const Gdiplus::Rect& rect)
{
	ofs << rect.X << " " << rect.Y << " " << rect.Width << " " << rect.Height << "\n";
	return ofs;
}
std::fstream& operator>>(std::fstream& ofs, Gdiplus::Rect& rect)
{
	ofs >> rect.X;
	ofs >> rect.Y;
	ofs >> rect.Width;
	ofs >> rect.Height;
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
	std::fstream& FileMgr::OpenFileForWrite()
	{
		static std::string strFileMode = "OverWriteMode = 2, ContinueWriteMode = 8 : ";
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
			std::cout << '\n';
			if (fileMode == 2 || fileMode == 8)
				break;
			std::cout << "Mode Wrong\n\n";
		}

		abPath = std::move(PathMgr::GetInst().MakeAbsolutePath(fileName));
		m_FileStream.open(abPath, std::ios_base::out | fileMode);

		assert(m_FileStream.is_open());

		std::cout << "File Open Succees(Write Mode)!\n\n";
		return m_FileStream;
	}
	std::fstream& FileMgr::OpenFileForRead(const std::string& emptyOrFileName)
	{
		std::string fileName = emptyOrFileName;

		if (fileName.empty())
		{
			std::cout << "Input File Name : ";
			std::getline(std::cin, fileName);
			std::cout << '\n';
		}

		std::string abPath;
		abPath.reserve(50);
		abPath = std::move(PathMgr::GetInst().MakeAbsolutePath(fileName));
		m_FileStream.open(abPath, std::ios_base::in);

		assert(m_FileStream.is_open());

		std::cout << "File Open Succees(Read Mode)!\n\n";
		return m_FileStream;
	}
}
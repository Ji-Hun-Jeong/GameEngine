#include "PathMgr.h"

namespace Game
{
	PathMgr::PathMgr()
	{

	}
	PathMgr::~PathMgr()
	{

	}
	void PathMgr::Initalize()
	{
		std::array<wchar_t, 255> strDirPath;
		GetCurrentDirectory(static_cast<DWORD>(strDirPath.size()), strDirPath.data());
		m_WorkingPathW = strDirPath.data();
		m_WorkingPathW += '/';

		std::string temp(m_WorkingPathW.begin(), m_WorkingPathW.end());

		m_WorkingPath = std::move(temp);

		std::cout << "WorkingPath : " + m_WorkingPath << '\n';
	}
	std::wstring PathMgr::MakeAbsolutePathW(const std::wstring& fileName)
	{
		std::wstring findResourceFilePath(L"../Release/Resource/");

		size_t absolutePathLength = m_WorkingPath.size()
			+ findResourceFilePath.size() + fileName.size();
		std::wstring absolutePath;
		absolutePath.reserve(absolutePathLength);

		absolutePath.append(m_WorkingPathW);
		absolutePath.append(findResourceFilePath);
		absolutePath.append(fileName);

		return absolutePath;
	}
	std::string PathMgr::MakeAbsolutePath(const std::string& fileName)
	{
		std::string findResourceFilePath("../Release/Resource/");

		size_t absolutePathLength = m_WorkingPath.size()
			+ findResourceFilePath.size() + fileName.size();
		std::string absolutePath;
		absolutePath.reserve(absolutePathLength);

		absolutePath.append(m_WorkingPath);
		absolutePath.append(findResourceFilePath);
		absolutePath.append(fileName);

		return absolutePath;
	}
}


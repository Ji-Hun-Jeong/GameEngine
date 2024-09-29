#pragma once
#include "Common.h"
namespace Game
{
	class PathMgr
	{
		SINGLE(PathMgr)
	public:
		void Initalize();
		const std::wstring& GetWorkingPathW() { return m_WorkingPathW; }
		const std::string& GetWorkingPath() { return m_WorkingPath; }

		std::wstring MakeAbsolutePathW(const std::wstring& fileName);
		std::string MakeAbsolutePath(const std::string& fileName);

	private:
		std::wstring m_WorkingPathW;
		std::string m_WorkingPath;
	};
}



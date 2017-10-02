#include "TaskTwo.h"
#include <iostream>
#include <windows.h>

DataTypes* TaskTwo::doTask()
{
	std::cout << "task two running" << std::endl;
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	double virtualMemUsed = (double)memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
	return new DataTypes(virtualMemUsed);
}

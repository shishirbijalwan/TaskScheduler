#include "TaskOne.h"
#include <iostream>
#include <random>
#include <windows.h>

DataTypes* TaskOne::doTask()
{
	std::cout << "task one running" << std::endl;

	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	double physMemUsed = (double)memInfo.ullTotalPhys - memInfo.ullAvailPhys;
	return new DataTypes(physMemUsed);
}



//int main()
//{
//	ITask *task = new TaskOne();
//	task->doTask();
//
//
//
//}
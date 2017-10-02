#include "TaskFactory.h"
/////////////////////////////////////////////////////////////////////
//  TaskFactory.cpp - object factory for task                        //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2015, SP1                            //
//  Platform:      Virtual box on Mac, Windows 10                  //
//  Application:   Task Scheduler                                  //
//  Author:        Shishir Bijalwan, Syracuse University           //
//                 (979) 587-6340, sbijalwa@syr.edu                //
/////////////////////////////////////////////////////////////////////

 ITask* TaskFactory::getTaskObject(std::string name)
{
	if (name == "TaskOne")
		return new TaskOne();
	else if (name == "TaskTwo")
		return new TaskTwo();
	else
		return nullptr;

}

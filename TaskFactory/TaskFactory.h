#ifndef TASKFACTORY_H
#define TASKFACTORY_H
/////////////////////////////////////////////////////////////////////
//  TaskFactory.h - object factory for task                        //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2015, SP1                            //
//  Platform:      Virtual box on Mac, Windows 10                  //
//  Application:   Task Scheduler                                  //
//  Author:        Shishir Bijalwan, Syracuse University           //
//                 (979) 587-6340, sbijalwa@syr.edu                //
/////////////////////////////////////////////////////////////////////

/*
Module Operations:
==================
This class has been created with a view that user should just know the name of the task needed, and should not be resposible for handling the lifetime of the task object (memory leak could happen). So in our system
the user provides the name of the task and task scheduler ask the Task Factory for its object.

Required files
- ITask.h, TaskFactory.h, TaskOne.h, TaskTwo.h
Build Command: devenv TaskScheduler.sln /rebuild debug
Maintenance History:
====================
ver 1.0
*/
#include "../ITask/ITask.h"
#include "../TaskOne/TaskOne.h"
#include "../TaskTwo/TaskTwo.h"

#include <string>

class TaskFactory
{
public:
	static ITask* getTaskObject(std::string name);

};

#endif
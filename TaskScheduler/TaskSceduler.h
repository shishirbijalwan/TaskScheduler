#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H
/////////////////////////////////////////////////////////////////////
//  TaskScheduler.h - To save the ouput of task                    //
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
This is the startup class for this project and controls all the process from accepting user input to reults being enqueued in the result queue of databaseDriver. It uses Task factory to get the task object and uses task controller to do
all the action requested by user like task scheduling, task duration update and task removal.

Required files
- Result.h, TaskScheduler.h, TaskController.h, ITask.h, TaskFactory.h
Build Command: devenv TaskScheduler.sln /rebuild debug
Maintenance History:
====================
ver 1.0
*/
#include<unordered_map>
#include"../TaskController/TaskController.h"
#include"../ITask/ITask.h"
#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"
#include "../TaskResult/TaskResult.h"
#include "../DatabaseWriter/DatabaseDriver.h"
class TaskScheduler
{
public:
	TaskScheduler();
	int addTask(int interval, std::string taskName);
	void execute(TaskController * taskcontroller, ITask * task);
	bool cancelTask(int task_id);
	bool changeInterval(int interval, int task_id);

private:
	std::unordered_map<int, TaskController*> taskList;
	std::unordered_map<int, ITask*> taskIdMap;
	static int task_id;
	DatabaseDriver* dbDriver;	 
};
#endif
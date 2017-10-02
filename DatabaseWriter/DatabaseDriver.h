#ifndef DATABASEDRIVER_H
#define DATABASEDRIVER_H
/////////////////////////////////////////////////////////////////////
//  DatabaseDriver.h - To save the ouput of task                    //
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
The purpose of this class is to take away the load of putting data in database from the task scheduler. As loading data can be time taking due to many reasons example connection failed. We won't want the the thread running task to wait for it
. So we decoupled the task execution and reult loading with the help of a blocking queue.

Required files
- DatabaseDriver.h, BlockingQueue.h, result.h, datatypes.h
Build Command: devenv TaskScheduler.sln /rebuild debug
Maintenance History:
====================
ver 1.0
*/

#include "../Cpp11-BlockingQueue/Cpp11-BlockingQueue.h"
#include "../TaskResult/TaskResult.h"
#include<thread>

class DatabaseDriver
{
public:
	void enqueue(TaskResult* testResult)
	{
		resultQueue->enQ(testResult);
	}
	
	DatabaseDriver()
	{
		resultQueue = new BlockingQueue<TaskResult*>();

		std::thread([this]() {
			writeToDatabase();
		}).detach();
	}

private:
	BlockingQueue<TaskResult*> *resultQueue;
	void writeToDatabase();
	std::string JsonData(TaskResult *taskResult);
	std::string getInserStatement(TaskResult *taskResult);
};

#endif
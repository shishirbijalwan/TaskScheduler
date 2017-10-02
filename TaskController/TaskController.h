#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H
/////////////////////////////////////////////////////////////////////
//  TaskController.h - Controls task execution                     //
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
This struct helps us in controlling all execution related things for a task, like change in interval or suspending a task. This class basically has flags and coditional variable which helps us in doing so.

Required files
- TaskController.h
Build Command: devenv TaskScheduler.sln /rebuild debug
Maintenance History:
====================
ver 1.0
*/
#include <mutex>
#include <condition_variable>
struct TaskController {
public:
	std::mutex mtx;
	std::condition_variable cv;
	int interval;
	bool isUpdated;
	bool shoudlContinue;
	int count;
	double maxOld;
	double minOld;
	double averageOld;
	TaskController(int interval);
};

#endif
/////////////////////////////////////////////////////////////////////
//  TaskScheduler.cpp - To save the ouput of task                    //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2015, SP1                            //
//  Platform:      Virtual box on Mac, Windows 10                  //
//  Application:   Task Scheduler                                  //
//  Author:        Shishir Bijalwan, Syracuse University           //
//                 (979) 587-6340, sbijalwa@syr.edu                //
/////////////////////////////////////////////////////////////////////
#include "TaskSceduler.h"
#include "../TaskFactory/TaskFactory.h"
#include "../TaskResult/TaskResult.h"

#include<thread>

#include <iostream>
int TaskScheduler::task_id=0;


TaskScheduler::TaskScheduler()
{

	dbDriver = new DatabaseDriver();
}

int TaskScheduler::addTask(int interval, std::string taskName)
{
	TaskController* taskcontroller = new TaskController(interval);
	taskList[task_id++]=taskcontroller;
	ITask *task = TaskFactory::getTaskObject(taskName);
	std::thread([this, taskcontroller, task]() {
		execute(taskcontroller, task);
	}).detach();

	taskIdMap[task_id - 1] = task;
	return task_id-1;
}

void TaskScheduler::execute(TaskController* taskcontroller,ITask* task) {
	std::unique_lock<std::mutex> l(taskcontroller->mtx);
	
	while (taskcontroller->shoudlContinue) {
		auto now = std::chrono::system_clock::now();
		taskcontroller->cv.wait_until(l, now + std::chrono::microseconds(taskcontroller->interval));
		if (!taskcontroller->isUpdated)
		{
			// for prototype i have done coding for double only, but in actual code we will need to use Datatypes object
			double tempResult = task->doTask()->getDoubleValue();
			if (taskcontroller->count == 0)
			{
				taskcontroller->averageOld = tempResult;
				taskcontroller->minOld = tempResult;
				taskcontroller->maxOld = tempResult;
				taskcontroller->count++;
			}
			else
			{;
				if (taskcontroller->minOld > tempResult)
					taskcontroller->minOld = tempResult;
				else if (taskcontroller->maxOld < tempResult)
					taskcontroller->maxOld = tempResult;
				taskcontroller->count++;
				taskcontroller->averageOld = ((taskcontroller->averageOld*(taskcontroller->count-1)) + tempResult) / (taskcontroller->count);
			}
			dbDriver->enqueue(new TaskResult(tempResult, taskcontroller->minOld, taskcontroller->maxOld, taskcontroller->averageOld));
		}
		else {
			taskcontroller->isUpdated = false;
		}
	}
}

bool TaskScheduler::cancelTask(int task_id)
{
	TaskController* taskcontroller = taskList[task_id];
	taskcontroller->shoudlContinue = false;
	taskcontroller->isUpdated = true;
	taskcontroller->cv.notify_one();
	delete taskcontroller; // deleteing controller
	delete taskIdMap[task_id]; //deleting task object
	return true;
}

bool TaskScheduler::changeInterval(int interval, int task_id)
{
	TaskController* taskcontroller = taskList[task_id];
	taskcontroller->isUpdated = true;
	taskcontroller->interval = interval;
	taskcontroller->cv.notify_one();
	return true;
}

int main()
{
	ITask* task = new TaskOne();

	TaskScheduler* ts = new TaskScheduler();
	int taskId=ts->addTask(3000000, "TaskOne");
	int taskId2 = ts->addTask(3000000, "TaskTwo");
	int i;
	std::cin >>i ;
	ts->changeInterval(300000, taskId);
	std::cin >> i;
	ts->cancelTask(taskId);
	ts->cancelTask(taskId2);

	std::cout << "stopped" << std::endl;
	return 0;
}

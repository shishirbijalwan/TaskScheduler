#include "TaskFactory.h"
#include <iostream>

bool test_getTaskObject_when_no_task_found()
{
	ITask * task = TaskFactory::getTaskObject("taskNotAvailable");

	if (!task) // it is nullptr
		return true;
	else
		return false;
}

bool test_getTaskObject_when_task_found()
{

	ITask * task = TaskFactory::getTaskObject("TaskOne");

	if (task) // it is not nullptr
		return true;
	else
		return false;

}
#ifdef TEST_TASKFACTORY
int main()
{
	if (test_getTaskObject_when_no_task_found())
		std::cout << " received nullptr test test_getTaskObject_when_no_task_found passesed" << std::endl;
   else
	   std::cout << " Didn't receive nullptr test test_getTaskObject_when_no_task_found failed" << std::endl;

	if (test_getTaskObject_when_task_found())
		std::cout << " received object test test_getTaskObject_when_task_found  passesed" << std::endl;
	else
		std::cout << " received nullptr test test_getTaskObject_when_task_found failed" << std::endl;

	return 0;
}

#endif
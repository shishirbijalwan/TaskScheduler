#ifndef TASKTWO_H
#define TASKTWO_H
#include "../ITask/ITask.h"

class TaskTwo : public ITask
{

public:
	virtual DataTypes* doTask();
	virtual ~TaskTwo() {}

};

#endif
#ifndef TASKONE_H
#define TASKONE_H

#include "../ITask/ITask.h"

class TaskOne : public ITask
{

public :
	virtual DataTypes* doTask();
	virtual ~TaskOne() {}

};

#endif

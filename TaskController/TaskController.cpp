#include "TaskController.h"

TaskController::TaskController(int interval) {
	this->interval = interval;
	isUpdated = false;
	shoudlContinue = true;
	count = 0;
	maxOld = 0;
	minOld = 0;
	averageOld = 0;
}
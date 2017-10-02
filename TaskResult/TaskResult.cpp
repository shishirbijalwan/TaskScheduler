#include "TaskResult.h"
/////////////////////////////////////////////////////////////////////
//  TaskResult.h - To save the ouput of task                       //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2015, SP1                            //
//  Platform:      Virtual box on Mac, Windows 10                  //
//  Application:   Task Scheduler                                  //
//  Author:        Shishir Bijalwan, Syracuse University           //
//                 (979) 587-6340, sbijalwa@syr.edu                //
/////////////////////////////////////////////////////////////////////


TaskResult::TaskResult(double currentOuput, double maxOutput, double minOutput, double averageOutput)
{
	this->averageOutput = averageOutput;
	this->currentOuput = currentOuput;
	this->maxOutput = maxOutput;
	this->minOutput = minOutput;

}

//
//int main()
//{
//	TaskResult* ts = new TaskResult(1.0, 1.0, 11.0, 11.1);
//
//}
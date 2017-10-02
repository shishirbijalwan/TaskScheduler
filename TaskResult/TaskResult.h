#ifndef TASKRESULT_H
#define TASKRESULT_H
/////////////////////////////////////////////////////////////////////
//  TaskResult.h - To save the ouput of task                       //
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
The reason of having this is to be able to save results in form of object and then we can have different functions which could help us in getting results in different format. In actual i will have multiple key value pairs to save
the results and have a vector of it as a member variable. But as for prototype i have hard coded the member variables. I haven't used datatypes as member variable for now to make code easier and as it was a prototype

Required files
- Result.h
Build Command: devenv TaskScheduler.sln /rebuild debug
Maintenance History:
====================
ver 1.0
*/
struct TaskResult
{   // in actual software these doubles will be DataTypes objects. so it can save various types of result
	double currentOuput;
	double maxOutput;
	double minOutput;
	double averageOutput;

	TaskResult(double currentOuput, double maxOutput, double minOutput, double averageOutput);
};
#endif
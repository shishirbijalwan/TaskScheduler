#ifndef ITASK_H
#define ITASK_H
/////////////////////////////////////////////////////////////////////
//  ITask.h - Interface to hold object of different task           //
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
The purpose of this iterface is to provide dynamic polymorphism at run time. It helps in decoupling the task scheduler with the implementation of various task that it needs to run.

Required files
- ITask.h
Build Command: devenv TaskScheduler.sln /rebuild debug
Maintenance History:
====================
ver 1.0
*/

#include "../DataTypes/DataTypes.h"

class ITask
{
public:
 virtual DataTypes* doTask() =0;
 virtual ~ITask() {};

};

#endif
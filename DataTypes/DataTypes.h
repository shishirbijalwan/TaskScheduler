#ifndef DATATYPES_H
#define DATATYPES_H
/////////////////////////////////////////////////////////////////////
//  DataTypes.h - To support different return types for task       //
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
The purpose of this package is to make the system more scalable from the side of supporting new task with different return types from existing ones. For now we have given support for integer, string and double,
based on the need to developer can add other types example float, char etc

Required files
- DataTypes.h
Build Command: devenv TaskScheduler.sln /rebuild debug
Maintenance History:
====================
ver 1.0
*/

#include <string>
class DataTypes
{
public:
	enum dataVariety
	{
		INT, 
		STR, 
		DOUBLE,
	};
	// dataType();
	DataTypes(int value);
	DataTypes(std::string val);
	DataTypes(double value);

	int getIntValue() { return intValue; }
	std::string getStringValue() { return stringValue; }
	double getDoubleValue() { return doubleValue; }
	bool ifVarietyisString();
	bool ifVarietyisInt();
	bool ifVarietyisDouble();

private:
	int intValue;
	std::string stringValue;
	double doubleValue;
	dataVariety variety;
};


#endif
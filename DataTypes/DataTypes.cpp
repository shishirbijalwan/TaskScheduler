/////////////////////////////////////////////////////////////////////
//  DataTypes.cpp - To support different return types for task       //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2015, SP1                            //
//  Platform:      Virtual box on Mac, Windows 10                  //
//  Application:   Task Scheduler                                  //
//  Author:        Shishir Bijalwan, Syracuse University           //
//                 (979) 587-6340, sbijalwa@syr.edu                //
/////////////////////////////////////////////////////////////////////
#include "DataTypes.h"

DataTypes::DataTypes(int value) : variety(INT), intValue(value)
{

}

DataTypes::DataTypes(std::string val) : variety(STR), stringValue(val)
{

}
DataTypes::DataTypes(double value) : variety(DOUBLE), doubleValue(value)
{

}


bool DataTypes::ifVarietyisString()
{
	return variety == STR;
}

bool DataTypes::ifVarietyisInt()
{
	return variety == INT;
}

bool DataTypes::ifVarietyisDouble()
{
	return variety == DOUBLE;
}

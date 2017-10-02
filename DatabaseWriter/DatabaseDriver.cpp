/////////////////////////////////////////////////////////////////////
//  DatabaseDriver.cpp - To save the ouput of task                 //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2015, SP1                            //
//  Platform:      Virtual box on Mac, Windows 10                  //
//  Application:   Task Scheduler                                  //
//  Author:        Shishir Bijalwan, Syracuse University           //
//                 (979) 587-6340, sbijalwa@syr.edu                //
/////////////////////////////////////////////////////////////////////
#include "DatabaseDriver.h"

void DatabaseDriver::writeToDatabase()
{
	while (true)
	{
		//std::cout << JsonData(resultQueue->deQ()) << std::endl;
		std::cout << getInserStatement(resultQueue->deQ()) << std::endl;
	}
}

std::string DatabaseDriver::JsonData(TaskResult *taskResult)
{

	std::string json = "{ \"result\" : "  + std::to_string( taskResult->currentOuput)+"\n" 
		             + "  \"max\" : " + std::to_string(taskResult->maxOutput) + "\n"
		             + "  \"min\" : " + std::to_string(taskResult->minOutput) + "\n"
		             + "  \"average\" : " + std::to_string(taskResult->averageOutput) + "}";
	return json;
}

std::string DatabaseDriver::getInserStatement(TaskResult * taskResult)
{
	std::string current = std::to_string(taskResult->currentOuput);
	std::string max = std::to_string(taskResult->maxOutput);
	std::string min = std::to_string(taskResult->minOutput);
	std::string average = std::to_string(taskResult->averageOutput);
	std::string sqlstatement = "INSERT INTO abe_account (current, max, min, average) VALUES ('" + current + "','" + max + "','" + min + "','" + average + "');";
	return sqlstatement;
}



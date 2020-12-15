#pragma once

#include <vector>
#include <string>
using namespace std;


// enumeration for the different array indices
enum arryaIndices 
{
	PROGRAM_NAME,
	FILE_NAME,
	COMMAND_LINE_ARGUMENTS_NUMBER
};

// enumeration for the different success and failure values
enum errorLabels
{
	SUCCESS,
	OPEN_FILE_FAILED,
	WRONG_COMMAND_LINE_ARGUMENTS_NUMBER
};

int parseFile(vector<string> &s, char *fileName);

int UsageMessage(char * programName);

int parseFile(vector<string> &s, char *fileName);



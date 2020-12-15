// lab1.cpp : Defines the entry point for the console application.
//
// Name: Yu Ren (466307)
// Date: 2019/2/5

#include "stdafx.h"
#include "Header.h"
#include "vector"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int UsageMessage(char * programName)
{
	cout << "usage: " << programName << " <input_file_name>" << endl;
	return WRONG_COMMAND_LINE_ARGUMENTS_NUMBER;
}

int main(int argc, char * argv[])
{
	// check if the user does enter exactly two arguments 
	// report error message if not
	if (argc == 2) 
	{
		char * fileName = argv[FILE_NAME];
		vector<string> s;
		vector<int> num;
		// check if the input file being read successfully
		if (parseFile(s, fileName) == SUCCESS)
		{
			cout << "Contain any other (non-digit) characters: " << endl;
			for (size_t i = 0; i < s.size(); ++i)
			{
				string temp = s[i];
				int count = 0;
				// check if the string contains any non digit characters
				for (int j = 0; j < int(temp.size()); ++j)
				{
					if (!isdigit(temp[j])) 
					{
						count++;
						break;
					}
				}
				// the case that the string contains only numeric digit characters
				if (count == 0)
				{
					istringstream numWord(temp);
					int x;
					numWord >> x;
					num.push_back(x);
				}
				// simply print the string to the standard output stream if contains non-digit characters
				else
				{
					cout << temp << endl;
				}
			}
			cout << endl << "Contain only numeric digit characters: " <<endl;
			for (size_t i = 0; i < num.size(); ++i)
			{
				cout << num[i] << endl;
			}
			return SUCCESS;
		}
		else
		{
			return OPEN_FILE_FAILED;
		}
	}
	else 
	{
		cout << "Wrong number of comand line arguments entered!" << endl;
		char * programName = argv[PROGRAM_NAME];
		return UsageMessage(programName);
	}

}

// function for parsing an input file
int parseFile(vector<string> &s, char *fileName)
{
	ifstream ifs(fileName); 
	if (ifs.is_open())
	{
		string line;
		// get a line from file into string
		// wrap string in a stream
		// pull words off the stream
		while (getline(ifs, line)) {
			istringstream record(line);
			string word;
			while (record >> word) {
				s.push_back(word);
			}
		}
		return SUCCESS;
	}
	// report error message if the input file is unable to open
	else
	{
		cout << "Fail to open the input file!" << endl;
		return OPEN_FILE_FAILED;
	}
}



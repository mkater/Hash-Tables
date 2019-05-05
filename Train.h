#pragma once
#include<string>

using namespace std;

class Train
{
public:

	string trainName;	//variables for train class
	int trainNumber;

	Train(string name_in, int number_in);	//constructor
	unsigned int Hash(int tablesize);
};

ostream & operator << (ostream & out, Train * t);	//override << for train
#include "Train.h"

Train::Train(string name_in, int number_in)	//constructor takes in string and int
{
	trainNumber = number_in;	
	trainName = name_in;
}

unsigned int Train::Hash(int tablesize)		//hash function takes in the size of table
{
	unsigned int value = trainNumber;
	for (unsigned int i = 0; i < trainName.size(); i++)
	{
		value += (trainNumber + 11) * value + trainName[i];	//hashes the trains
	}
	return value % tablesize;		//to a specific value
}

ostream & operator << (ostream & out, Train * t)
{

	out << t->trainName << " " << t->trainNumber;		//override << to print the trains
	return out;
}
#include"HashTable.h"
#include<iostream>
#include<iterator>
using namespace std;

HashTable::HashTable()		//constructor for hashtables
{
	numberOfEntries = 0;
	sizeOfTable = 2;
	table.resize(sizeOfTable);		//resizes table to be a vector of a vector of train pointers the size of sizeoftable
}

bool HashTable::Insert(Train * t)
{

	int myHash = t->Hash(sizeOfTable);		//hashes the train

	for (unsigned int i = 0; i < table[myHash].size(); i++)		//loops through the hash
	{
		if (table[myHash].at(i)->trainName == t->trainName && table[myHash].at(i)->trainNumber == t->trainNumber) //if the train matches one in hash
		{
			return false;		//return false, it has already been inserted
		}
	}

		table[myHash].insert(table[myHash].begin(), t);		//else it hasn't been inserted, so insert it
		numberOfEntries++;
	

	if (numberOfEntries > (sizeOfTable * 2))		//if this triggers we call rehash function
	{
		Rehash();
	}

	return true;		//and return true, as something was inserted
}

void HashTable::Print(ostream & out)		
{
	for (unsigned int i = 0; i < table.size(); i++)		//loops through the table and prints out each entry
	{
		out << i << ": " <<table[i] << endl;
	}
}

void HashTable::Rehash()
{
	
	vector<Train *> tptrTemp;		//temporary pointer vector to hold the values

	for (unsigned int i = 0; i < table.size(); i++)		//nested for loop going through each entry of each list of table
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			tptrTemp.push_back(table[i][j]);		//and pushing it onto the pointer vector temporary variable
		}
		table[i].clear();		//clearing it from table
	}

	sizeOfTable *= 2;
	numberOfEntries = 0;

	table.resize(sizeOfTable);		//resizing table to new sizeoftable

	for (int i = 0; i < tptrTemp.size(); i++)	//looping through new temp vector
	{
		Insert(tptrTemp[i]);		//and calling insert function to insert into each spot in the created hash
	}

}


bool HashTable::find(Train * t)
{

	int myHash = t->Hash(sizeOfTable);		//hash the train

	for (unsigned int i = 0; i < table[myHash].size(); i++)		//loop through table
	{
		if (table[myHash].at(i)->trainName == t->trainName && table[myHash].at(i)->trainNumber == t->trainNumber)	//if train matches train in hash/ is found
		{
			return true;	//return true
		}
	}

	return false;
}

void HashTable::Remove(Train * t)
{
	
	vector<Train *>::const_iterator itr;	//use iterator for this as removing from vector causes issues
	int myHash = t->Hash(sizeOfTable);		//hash again

	if (find(t) == true)		//calling find, only doing remove if item is in hashtable
	{

		for (itr = table[myHash].begin(); itr != table[myHash].end();)		//iterate through the table
		{
			if ((*itr)->trainName == t->trainName && ((*itr)->trainNumber == t->trainNumber))	//if it found the match
			{
				itr = table[myHash].erase(itr);	//erase
			}
			else
			{
				itr++;	//otherwise increment the iterator
			}
		}
	}
	
}

ostream & operator << (ostream & out, vector<Train *> tPtr)		//override <<
{

	for (unsigned int i = 0; i < tPtr.size(); i++)	//looping through vector of train pointers
	{
		out << tPtr[i] << "   ";				//already overriden in train to print train name and #, so don't need to do it here.
	}
	return out;
}
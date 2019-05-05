#pragma once
#include<vector>
#include"Train.h"
class HashTable
{
private:
	int sizeOfTable;
	int numberOfEntries;
	vector<vector<Train *>> table;	//a vector of vector pointers for the table
	void Rehash();		//rehash and find private as they are only used within class
	bool find(Train * t);

public:		//public functions for the hashtable class
	HashTable();
	bool Insert(Train * t);		
	void Print(ostream & out);
	void Remove(Train * t);
};

ostream & operator << (ostream & out, vector<Train *> tPtr);	//override << to print the vector of train pointers
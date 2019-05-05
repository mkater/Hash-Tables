#include"HashTable.h"
#include"Train.h"
#include<iostream>


using namespace std;

int main()

{
	Train train1("4-4-2", 343);	//creating trains
	Train train2("2-8-0", 344);
	Train train3("4-0-4", 345);
	HashTable myHash;			//creating hash


	myHash.Print(cout);		//print empty hash
	cout << endl;
	myHash.Insert(&train1);	//insert trains into hash
	myHash.Insert(&train2);
	myHash.Insert(&train3);
	cout << "original print: " << endl;
	myHash.Print(cout);		//print them
	cout << endl;


	myHash.Insert(&train1);	//try inserting same trains again
	myHash.Insert(&train2);
	myHash.Insert(&train3);
	cout << "print after adding same three again:" << endl;
	myHash.Print(cout);		//print, duplicates are not added
	cout << endl;
	Train train4("2-8-0", 1);	//add a bunch of trains
	Train train5("2-8-0", 2);
	Train train6("2-8-0", 3);
	Train train7("12-0-0", 42);
	Train train8("12-0-12", 84);
	Train train9("2-2", 2);
	Train train10("4-4", 4);

	myHash.Insert(&train4);	//insert a bunch of trains into hash
	myHash.Insert(&train5);
	myHash.Insert(&train6);
	myHash.Insert(&train7);
	myHash.Insert(&train8);
	myHash.Insert(&train9);
	myHash.Insert(&train10);
	cout << "print after adding more trains: " << endl;
	myHash.Print(cout);
	cout << endl;
	myHash.Remove(&train1);	//remove three original trains
	myHash.Remove(&train2);
	myHash.Remove(&train3);
	Train train11("2-8-0", 99);	//create a new train, insert and then remove the train
	myHash.Insert(&train11);
	myHash.Remove(&train11);
	cout << "print after deleting the trains: " << endl;
	myHash.Print(cout);	//final print
	cin.ignore();
}
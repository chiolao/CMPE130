/*
 * HashTable.h
 *
 *  Created on: Dec 2, 2017
 *      Author: arthur moua
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctype.h>
using namespace std;

struct cars {

    cars()
    {
        distance = 0;
        license = "";
    }

    cars(string s, int b)
    {
    	license = s;
        distance = b;
    }
	int distance;
	string license;

};

class HashTable {

public:

	//Default constructor - initializes all values to 0
	HashTable();

	//Constructor - initialize size of the array and the absolute position/distance of the garage
	HashTable(int size, int distance);

	//Do not edit the next three functions without telling me
	//They are required for finding and ordering the garages/hash tables in main()

	int getLocation();

	int getDist();

	int getSpaceLeft();

	void setDist(int d);

	//Do not edit
	int hash(int dist);

	bool isFull();

	void insert(cars p);

	bool loadFactor();

	bool search(string s, bool d);

	void report();



private:

	struct Node {
        Node()
        {
            car = cars();
            //next = NULL;
            del = true;
        }
		cars car;
		//Node* next;
        bool del;

	};

	Node *inventory;
	int MAX_SIZE;
	int currentSize;
	//absolute distance of the garage
	int location;
	//Used to determine which garage to direct user to
	int dist;
	//statistic variables - ignore for now
	float alpha;
	float searchCount;
	float totalLoop;



};




#endif /* HASHTABLE_H_ */

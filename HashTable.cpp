/*
 * HashTable.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: arthur moua
 */
#include "HashTable.h"

HashTable::HashTable()
{
	MAX_SIZE = 0;
	currentSize = 0;
	location = 0;
	dist = 0;
	alpha = 0;
	counter = 0;
	inventory[0];
}

HashTable::HashTable(int size, int distance)
{
	MAX_SIZE = size;
	currentSize = 0;
	location = distance;
	dist = 0;
	alpha = 0;
	counter = 0;
	inventory = new Node[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Node n;
		inventory[i] = n;
	}

}

bool HashTable::loadFactor()
{
	alpha = currentSize/MAX_SIZE;
	if(alpha > .5)
	{
		//counter++;

		return true;
	}
	else
	{
		return false;
	}

}

int HashTable::getLocation()
{
	return location;
}

int HashTable::getDist()
{
	return dist;
}

void HashTable::setDist(int d)
{
	 dist = d;
}

int HashTable::hash(int dist)
{
/*    int value = dist;
    while (inventory[value] != NULL)
    {
    	value = (value+1)% MAX_SIZE;
    }*/

	int value = (dist % MAX_SIZE);

	return value;
}

void HashTable::insert(cars p)
{
	cout <<"currentSize: " << currentSize << endl;
	cout <<"MAX_SIZE: " << MAX_SIZE << endl;
    if(currentSize == MAX_SIZE)
    {
        cout << "garage is full" << endl;
    }
    else
    {
    	int index = hash(p.distance);
		//Node* node = new Node;
    	Node node;
		//node->car = p;
    	node.car = p;
    	node.del = false;
		//node->next = inventory[index];
		bool inserted = false;
		while(inserted == false)
		{
/*			if(inventory[index] == NULL)
			{
				inventory[index] = node;
				inserted = true;
			}
			else
			{*/
				if(inventory[index].del == true)
				{
					inventory[index] = node;
					inserted = true;
				}
				if(index++ > MAX_SIZE)
				{
					index = 0;
				}
				else
				{
					index++;
				}

			//}
		}

		//currentSize++;

		cout << currentSize << endl;
		cout << "Inserted "<< p.license << " distance ="<< p.distance << " at parking number" << index <<endl;
		currentSize ++ ;
    }
}

bool HashTable::search(string key)
{

	string s;
	char c[2];
	if(key.size() == 5)
	{
		for (int i = 0; i<4; i++)
		{
			s = s + key[i];

		}
		c[1] = key[4];
	}
	else if(key.size() == 6)
	{
		for (int i = 0; i<6; i++)
		{
			s = s + key[i];

		}
		c[0] = key[5];
		c[1] = key[6];
	}

	int d;
	d= atoi(c);

	int index = hash (d);  //call hash function;

	//int index = hash(key);  //call hash function;
	if (inventory[index].car.license == s)
	{
		//cout <<inventory[index]->car.license << "is found" << endl;
		return true;
	}
	else
	{

		index++;
		int x = 0;
		while(x != MAX_SIZE)
		{
			if (inventory[index].car.license == s)
			{
				//cout <<inventory[index]->car.license << "is found" << endl;
				return true;
			}

			if(index++ > MAX_SIZE)
			{
				index = 0;
			}
			else
			{
				index++;
				x++;
			}
		}

		//cout<< "You car is not in garage " << endl;
		return false;
	}
}

//do not write a code for this before asking me I have this under development - Arthur
void HashTable::report()
{
/*	// find largest list
	int max = 0;
	int total = 0;
	int num_filled = 0;

	for (int i = 0; i < MAX_SIZE; i++) {
		int size = 0;
		Node* current = inventory[i];
		while (current) {
			size++;
			current = current->next;
		}
		if (size > 0) {
			num_filled++;
			total += size;
		}
		if (size > max) {
			max = size;
		}
	}
    for (int i=0; i< MAX_SIZE; i++)
    {

    //    cout << inventory[i] << endl;
    }

	cout << "The table has " << total << " elements." << endl;
	cout << num_filled << " lists have data out of " << MAX_SIZE << " total." << endl;
	cout << "The average filled list has " << ((float)total / num_filled) << " elements." << endl;
	cout << "Largest list has " << max << " elements." << endl;*/
}

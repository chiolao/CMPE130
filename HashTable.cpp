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
	searchCount = 0;
	totalLoop = 0;
	inventory[0];
}

HashTable::HashTable(int size, int distance)
{
	MAX_SIZE = size;
	currentSize = 0;
	location = distance;
	dist = 0;
	alpha = 0;
	searchCount = 0;
	totalLoop = 0;
	inventory = new Node[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Node n;
		inventory[i] = n;
	}

}

bool HashTable::loadFactor()
{

	float x = currentSize;
	float y = MAX_SIZE;
	alpha = x/y;
	//cout << "alpha: " << alpha << endl;
	if(alpha > .5)
	{
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

int HashTable::getSpaceLeft()
{
	return (MAX_SIZE - currentSize);
}

void HashTable::setDist(int d)
{
	 dist = d;
}

int HashTable::hash(int dist)
{
	int value = (dist % MAX_SIZE);

	return value;
}

bool HashTable::isFull()
{
	return (currentSize == MAX_SIZE);
}

void HashTable::insert(cars p)
{
	/*cout <<"currentSize: " << currentSize << endl;
	cout <<"location: " << location << endl;*/
    if(currentSize >= MAX_SIZE)
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
				index++;
				if(index > (MAX_SIZE-1))
				{
					index = 0;
				}
		}

		//comment out during Prod release
		//cout << currentSize << endl;
		//cout << "Inserted "<< p.license << " distance = "<< p.distance << " at parking number " << index <<endl;
		currentSize ++ ;
    }
}

bool HashTable::search(string key, bool d)
{
	string s, c, k, b;
	int x, y;

	size_t z = key.find("CMPE");
	if(z == std::string::npos )
	{
		cout << "You entered the wrong key, please try again." << endl;
		return false;
	}

	k = key.substr(z);

	b = k.substr(4);

	y = stoi(b);


	s = key.substr(0,y);

	if(isdigit(key[y+1]))
	{
		c = key.substr(y,2);
	}
	else
		c = key.substr(y,1);

/*	cout << "key: " << key << endl;
	cout << "k: " << k << endl;
	cout << "b: " << b << endl;
	cout << "y: " << y << endl;
	cout << "s: " << s << endl;
	cout << "c: " << c << endl;*/


	/*s = key.substr(0,4);
	c = key.substr(4);*/
	//cout << "value of s: " << s << endl;
	//cout << "value of c: " << c << endl;

//needs to be fixed
/*	char c[2];
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
	}*/

	int a;
	//a= atoi(c);
	a = stoi(c);
	//cout << "value of a: " << a << endl;

	int index = hash (a);  //call hash function;

	if (inventory[index].car.license == s && d == false)
	{
		if(inventory[index].del != true )
		{
			//cout <<inventory[index]->car.license << "is found" << endl;
			searchCount++;
			totalLoop++;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{

		//index++;
		int t = 0;
		while(t != MAX_SIZE)
		{
			if (inventory[index].car.license == s)
			{
				//cout <<inventory[index]->car.license << "is found" << endl;
				if(inventory[index].del != true && d == true)
				{
					inventory[index].del = d;
					currentSize--;
					searchCount++;
					totalLoop = totalLoop + t + 1;
					return true;
				}
				else if(inventory[index].del != true && d == false)
				{
					searchCount++;
					totalLoop = totalLoop + t + 1;
					return true;
				}
				else
				{
					cout << "reached" << endl;
					return false;
				}

			}
			if(index++ > (MAX_SIZE-1))
			{
				index = 0;
			}
			else
			{
				t++;
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
    }*/

	cout << "The garage has " << currentSize << "/" << MAX_SIZE << " cars." << endl;
	cout << "The total searches have resulted in a " << searchCount/totalLoop*100 << "% success rate." << endl;

}

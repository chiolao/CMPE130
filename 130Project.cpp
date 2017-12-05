// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "HashTable.h"
#include <stdlib.h>

// main program
int main() {
	HashTable table1(20, 10), table2(20, 20), table3(3, 30), table4(3, 40), table5(3, 50);

	HashTable *ary1[5] = {&table1, &table2, &table3, &table4, &table5};

	table1.insert(cars("car1", 5));
	table1.insert(cars("car2", 5));
	table1.insert(cars("car3", 6));
    table2.insert(cars("car4", 21));
    table2.insert(cars("car5", 15));
    //table2.insert(cars("car6", 18));

	int choice;
	do {
		cout << "Press 1 to find parking" << "\n";
		cout << "Press 2 to search for your car." << "\n";
		cout << "Press 3 to show the information of a parking lot" << "\n";
		cout << "Press 4 to exit the program" << "\n";
		cin >> choice;

		if (choice == 1)
		{
			HashTable *ary2[5], *temp;
			string lic, s;
			int dis, j;

			cout << "What is your license?" << endl;
			cin >> lic;
			cout << "what is your distance" << endl;
			cin >> dis;

			//only uncomment if you are using c-string
			/*char cstr[15];
			for (int i = 0; i < 15; i++)
			{
				cstr[i] = lic[i];
			}*/


			//This section orders the garages based on absolute distance from the destination from closest to farthest.
			//I stored the tables in an array so we can easily access the closest garages.
			for(int i = 0; i < 5; i++)
			{
				ary1[i]->setDist(abs(ary1[i]->getLocation() - dis));
				if(i == 0)
				{
					ary2[i] = ary1[i];
				}
				else
				{
					ary2[i] = ary1[i];
					temp = ary2[i];
					j = i - 1;
					while (j >= 0 && ary2[j]->getDist() > temp->getDist())
					{
						ary2[j+1] = ary2[j];
						j = j-1;
					}
					ary2[j+1] = temp;
				}

			}

			//Recall that load factor is how full a hash table is.
			//Right now I have it set to .5 (half full), but if you want to tweak this value just look in HashTable.cpp loadFactor()
			if(ary2[0]->isFull() == true)
			{
				cout << "The nearest parking garage is full." << endl;
				cout << "Do you want to be redirected to the next nearest garage?(y/n)" << endl;
				cin >> s;

				if( s == "n") cout << "Sorry for being unable to satisfy your needs. Please use our app again later as parking spaces may have become available then" << endl;
			}
			else if((ary2[0]->loadFactor() != true) && (ary2[0]->isFull() != true))
			{
				ary2[0]->insert(cars(lic, dis));
				cout << "Your car has been inserted" << endl;

				string key = to_string(ary2[0]->getLocation()) + lic + to_string(dis) + "CMPE" + to_string(lic.length());
				cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;
			}
			else if((ary2[0]->loadFactor() == true) && (ary2[0]->isFull() != true))
			{
				cout << "The nearest parking garage has limited space left." << endl;
				cout << "To reduce the chances of parking problems we recommend parking in the next nearest garage" << endl;
				cout << "Do you want to be redirected?(y/n)" << endl;
				cin >> s;

				if(s == "n")
				{
					ary2[0]->insert(cars(lic, dis));
					cout << "Your car has been inserted" << endl;

					string key = to_string(ary2[0]->getLocation()) + lic + to_string(dis) + "CMPE" + to_string(lic.length());
					cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;
				}
			}

			if(s == "y")
			{
				if(ary2[1]->isFull() == true && ary2[1]->isFull() == true && ary2[2]->isFull() == true && ary2[3]->isFull() == true && ary2[4]->isFull() == true)
				{
					cout << "Well this is embarrassing, all garages are full." << endl;
					cout << "Sorry for being unable to satisfy your needs. Please use our app again later as parking spaces may have become available then" << endl;
				}
				else if(ary2[1]->isFull() == true)
				{
					cout << "Well this is embarrassing, the 2nd nearest garage is full." << endl;
					cout << "To prevent this from happening again here are the next three nearest garages and their distances from your destination and available space:" << endl;
					cout << "Third nearest garage is " << ary2[2]->getDist() << " miles from your destination." << "It has " << ary2[2]->getSpaceLeft() << " spaces left." << endl;
					cout << "Fourth nearest garage is " << ary2[3]->getDist() << " miles from your destination." << "It has " << ary2[3]->getSpaceLeft() << " spaces left." << endl;
					cout << "Fifth nearest garage is " << ary2[4]->getDist() << " miles from your destination." << "It has " << ary2[4]->getSpaceLeft() << " spaces left." << endl;
					cout << "If you would like to be redirected to one of the garages above enter: 3, 4, or 5" << endl;
					cout << "Otherwise, if you would like to find your own parking space enter: n" << endl;
					cin >> s;

					if( s == "n") cout << "Sorry for being unable to satisfy your needs. Please use our app again later as parking spaces may have become available then" << endl;
					else if(s == "3")
					{
						ary2[2]->insert(cars(lic, dis));
						cout << "Your car has been inserted" << endl;

						string key = to_string(ary2[2]->getLocation()) + lic + to_string(dis) + "CMPE" + to_string(lic.length());
						cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;
					}
					else if(s == "4")
					{
						ary2[3]->insert(cars(lic, dis));
						cout << "Your car has been inserted" << endl;

						string key = to_string(ary2[3]->getLocation()) + lic + to_string(dis) + "CMPE" + to_string(lic.length());
						cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;
					}
					else if(s == "5")
					{
						ary2[4]->insert(cars(lic, dis));
						cout << "Your car has been inserted" << endl;

						string key = to_string(ary2[4]->getLocation()) + lic + to_string(dis) + "CMPE" + to_string(lic.length());
						cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;
					}
				}
				else
				{
					ary2[1]->insert(cars(lic, dis));
					cout << "Your car has been inserted" << endl;

					string key = to_string(ary2[1]->getLocation()) + lic + to_string(dis) + "CMPE" + to_string(lic.length());
					cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;
				}

			}


			cout << endl;
		}
		else if (choice == 2) //assume that search function already has the output according to the result: found or not found
		{
			string key1, key2, s, x;
			bool d = false;
			int garage;
			cout << "What is your key?" << endl;
			cin >> key1;
			cout << "Are you leaving?(y/n)" << endl;
			cin >> x;

			if(x == "y") d = true;

			//only uncomment if there will be garages 100+miles away included
			/*if(isdigit(key1[2]))
			{
				s = key1.substr(0,3);
				key2 = key1.substr(3);
			}*/

			if(isdigit(key1[1]))
			{
				s = key1.substr(0,2);
				key2 = key1.substr(2);
			}
			else
			{
				s = key1.substr(0,1);
				key2 = key1.substr(1);
			}

			if(isdigit(key1[0]))
			{
				//Use stoi for string to int
				//use atoi for c-string to int
				garage = stoi(s);
				//garage = atoi(s);
				if(ary1[0]->getLocation() == garage || ary1[1]->getLocation() == garage || ary1[2]->getLocation() == garage || ary1[3]->getLocation() == garage || ary1[4]->getLocation() == garage)
				{
					HashTable *temp;

					for(int i = 0; i < 5; i++)
					{
						if(ary1[i]->getLocation() == garage)
						{
							temp = ary1[i];
						}
					}

					if (temp->search(key2, d) == 1)
					{
						cout << "The car was found" << endl;
						if(d == true) cout << "Your car was successfully removed from the system. Thank you for using our app" <<  endl;

					}
					else
					{
						cout << "The system cannot find the car" << endl;
					}
				}
				else
				{
					cout << "You entered the wrong key, please try again." << endl;
				}
			}
			else
			{
				cout << "You entered the wrong key, please try again." << endl;
			}

			cout << endl;

		}

		else if (choice == 3)
		{
			//cout << "Under construction - ignore" << endl;
			table1.report();
			table2.report();
			table3.report();
			table4.report();
			table5.report();

			cout << endl;
		}

	} while (choice != 4);

		return 0;
}


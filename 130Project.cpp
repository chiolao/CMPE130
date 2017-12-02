// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "HashTable.h"
#include <stdlib.h>

// main program
int main() {
	HashTable table1(3, 10), table2(3, 20), table3(3, 30), table4(3, 40), table5(3, 50);

	HashTable ary1[5] = {table1, table2, table3, table4, table5};

	table1.insert(cars("car1", 5));
	table1.insert(cars("car2", 5));
    table1.insert(cars("car3", 6));
    table1.insert(cars("car4", 1));

	int choice;
	do {
		cout << "Press 1 to find parking" << "\n";
		cout << "Press 2 to search for your car" << "\n";
		cout << "Press 3 to leave the garage" << "\n";
		cout << "Press 4 to show the information of a parking lot" << "\n";
		cout << "Press 5 to exit the program" << "\n";
		cin >> choice;

		if (choice == 1)
		{
			HashTable ary2[5], temp;
			string lic, s;
			int dis, j;

			cout << "What is your license?" << endl;
			cin >> lic;
			cout << "what is your distance" << endl;
			cin >> dis;

			/*char cstr[15];
			for (int i = 0; i < 15; i++)
			{
				cstr[i] = lic[i];
			}*/


			//This section orders the garages based on absolute distance from the destination from closest to farthest.
			//I stored the tables in an array so we can easily access the closest garages.
			for(int i = 0; i < 5; i++)
			{
				ary1[i].setDist(abs(ary1[i].getLocation() - dis));
				if(i == 0)
				{
					ary2[i] = ary1[i];
				}
				else
				{
					ary2[i] = ary1[i];
					temp = ary2[i];
					j = i - 1;
					while (j >= 0 && ary2[j].getDist() > temp.getDist())
					{
						ary2[j+1] = ary2[j];
						j = j-1;
					}
					ary2[j+1] = temp;
				}
			}

			//Recall that load factor is how full a hash table is.
			//Right now I have it set to .5 (half full), but if you want to tweak this value just look in HashTable.cpp loadFactor()
			if(ary2[1].loadFactor() == true)
			{
				cout << "The nearest parking garage has limited space left." << endl;
				cout << "To reduce the chances of parking problems we recommend parking in the next nearest garage" << endl;
				cout << "Do you want to be redirected?(Y/N)" << endl;
				cin >> s;

				if(s == "Y")
				{
					ary2[2].insert(cars(lic, dis));
				}
			}
			else
			{
				ary2[1].insert(cars(lic, dis));
				cout << "Your car has been inserted" << endl;

				//Need to install patch for compiler, string based functions are not complete b/c I get compiler errors due to a package error.
				//First 2-3 elements of the string reserved for garage location(int value) so we can determine which garage to parse as seen below.
				//Using the idea below we can now have an unrestricted license plate string, ill update the search function latter.

				//string key = to_string(ary2[1].getLocation) + lic + to_string(dis);
				//cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;
			}

/*			table.insert(car(cstr, dis));
			cout << "Your car has been inserted" << endl;
			string key = lic + to_string(dis);
			cout << "Your recipt(key) is " << key << " , and you can use it for search or delete" << endl;*/

		}
				else if (choice == 2) //assume that search function already has the output according to the result: found or not found
		{
			string key1, key2, s;
			int garage;
			cout << "What is your key?" << endl;
			cin >> key1;

			if(key1.length() == 8)
			{
				s = key1.substr(0,2);
				key2 = key1.substr(2);
			}
			if(key1.length() == 9)
			{
				s = key1.substr(0,3);
				key2 = key1.substr(3);
			}

			//Use stoi for string to int
			//use atoi for c-string to int
			garage = std::stoi(s);
			//garage = std::atoi(s);

			HashTable temp;

			for(int i = 0; i < 5; i++)
			{
				if(ary1[i].getLocation() == garage)
				{
					temp = ary1[i];
				}
			}

			if (temp.search(key2))
			{
				cout << "The car is found" << endl; //how to output the location of the car

			}
			else
			{
				cout << "The system cannot find the car" << endl;
			}


		}
/*		else if (choice == 3)
		{
			cout << "what car you want to delete?" << endl;
			table.delete(key); //assumue we have the delete function with the parameter as key. the delete function has the output showing if is successful or not
		}

		//do not write a code for this before asking me I have this under development - Arthur
		else if (choice == 4)
		{
			cout << "The overall information of the parking lot will be givn as followed" << endl;
			//table.report(); // dont know what type of function of showing information, assume its a void function and show the overall information
		}*/
	} while (choice != 5);

		return 0;
}


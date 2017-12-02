// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

// the most things we can store in the table
const int MAX_SIZE = 20;
const int MAX_SIZE2 = 20;
int currentSize =0;

// a product with a code & price
struct car {
    car (const char* a = "", int b=0)
    {
        strcpy(lience, a);
        distance= b;
    }
	int distance;
	char lience[15];
  
};

// the hash table class
class HashTable {
public:
	// set all linked lists to empty
	HashTable() {
		for (int i = 0; i < MAX_SIZE; i++) {
			inventory[i] = NULL;
		}
	}

	// insert a product
	void insert(car p) {
        // hash the product
        int floor;
        cout << "current parking garage " ;
        floor = whichFloor(currentSize);
		int index = hash(p.distance);
        
        if(floor == 1){
            
            
		// make a new node at the start of this list
		Node* node = new Node;
		node->car = p;
		node->next = inventory[index];
		inventory[index] = node;
        
        cout << "" <<floor << endl;
       
 		cout << "Inserted "<<p.lience << " distance ="<< p.distance << " at parking number" << index<<endl;
        currentSize ++ ;
        }
            else if(floor == 2){
                
                // make a new node at the start of this list
                Node* node = new Node;
                node->car = p;
                node->next = inventory2[index];
                inventory2[index] = node;
                
                cout << "" <<floor << endl;
                
                cout << "Inserted "<<p.lience << " distance ="<< p.distance << " at parking number" << index<<endl;
                currentSize ++ ;
                
                
            }
	}


	// lookup a product's price
    void search (string key)
    {
    /*
        for (int i=0; i< MAX_SIZE; i++){
            
        if (key == i && inventory[i] !=NULL)
            cout <<"Your key = "<<key<< " is found" << endl;
        else   {}
        }
     */
        string s, x;
        if(key.size() == 5)
        {
            s = key[0-3];
            x = key[4];
        }
        else if(key.size() == 6)
        {
            s = key[0-4];
            x = key[5];
        }
        
        int d = atoi(x);
        
        int index = //call hash function;
        if(inventory[index].car.lience == s)
        {
            //return true;
        }
        else
        {
            for(int i = 1; i < 20; i++)
            {
                
            }
        }
            
    }
	
	

	// hash a string into am index
	int hash(int dist) {
        int value = 0;
      
        int whatFloor;
        whatFloor = whichFloor(currentSize);
      //  cout<<currentSize<<endl;
    if (whatFloor == 1){
       
         while (inventory[value] != NULL && value <=MAX_SIZE)
        {
            value = dist % 20;
        }
        }
        
        else
          {
                while(inventory2[value] != NULL&& value <=MAX_SIZE)
                    value = dist %20;
                
            }

		// mod by size to prevent overflow
		return value;
	}
    
    int whichFloor (int a)
    {
        int floor;
        if (currentSize < 5){// Zijian wanted to prevent many cars in one garage. so if we have a maxsize = 20, if it is 10 cars, then should go to other garage.
                     floor =1;
        return floor;
        }
        else{
          
            floor =2;
            return floor;
        }
       
    }

	// report how good the hashing was
	void report() {
		// find largest list
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
		cout << "Largest list has " << max << " elements." << endl;
	}

private:
	// a node in one of our linked lists
	struct Node {
		car car;
		Node* next;
        bool del;

	};

	// the products are all stored in an array
    
	Node inventory[MAX_SIZE];
    //Node* inventory2[MAX_SIZE2];
    //Node* floor[3];
};

// main program
int main() {
	HashTable table;

	// insert 500 products
	table.insert(car("Car1", 5));
  	table.insert(car("Car2", 7));
    table.insert(car("Car3", 3));
    table.insert(car("Car4", 5));
    table.insert(car("Car5", 6));
    table.insert(car("Car6", 7));
    table.insert(car("Car7", 8));
    table.insert(car("Car8", 9));
    table.search(0);
    table.search(7);
    table.search(3);
    table.search(7);
    //table.search("car1(distance)"
    
    /* 
     table.insert(car("Car2", 2));
     table.insert(car("Car3", 4));
     table.insert(car("Car4", 5));
     table.insert(car("Car5", 6));
     table.insert(car("Car6", 7));
     table.insert(car("Car7", 8));
     table.insert(car("Car8", 9));
     table.insert(car("Car9", 8));
     table.insert(car("Car10", 8));
     
     table.insert(car("Car11", 8));
    table.insert(car("Car12", 8));
    table.insert(car("Car13", 8));
    table.insert(car("Car14", 8));
    table.insert(car("Car15", 8));
    table.insert(car("Car16", 8));
    table.insert(car("Car17", 8));
    table.insert(car("Car18", 8));
    table.insert(car("Car19", 8));
    table.insert(car("Car20", 8));*/
 
	// print the report
	//table.report();
    
    /*do{
        cout << "Press 1 to select a floor to view to select parking" << "\n";
        cout << "Press 2 for the 5 nearest open parking spots on each floor" << "\n";
        cout << "Press 3 to view all cars parked from longest to shortest time spent" << "\n";
        cout << "Press 4 to leave the garage" << "\n";
        cout << "Press 5 to quit" << "\n";
        
        cin >> x;
        
        if(x == 1)
        {
            int a = 0;
            int b = 0;
            string s;
            
            //Select a floor
            cout << "Which floor (1-5) do you want to view?\n";
            cin >> a;
            cout << "Floor level " << a << ":\n";
            test.print(a);
            
            
            //Select a parking spot and give additional information
            cout << "There are 100 total parking spots on this floor.\n";
            cout << "Please select one of the empty parking spaces by\n";
            cout << "entering the corresponding parking spot value (1-100).\n";
            cin >> b;
            //elements go from 0-99 so subtract 1
            b = b-1;
            
            cout << "Please enter your car's id: \n";
            cin >> s;
            //cout << s;
            car obj(s,a,b);
            test.add(obj);
            
            //add insertionSortAdd function here
            
            
            
            //Add empty line space for clarity when "menu" reappears
            cout << "\n";
            
        }
        else if(x == 2)
        {
            test.getFiveSpaces(1);
            test.getFiveSpaces(2);
            test.getFiveSpaces(3);
            test.getFiveSpaces(4);
            test.getFiveSpaces(5);
            cout << "\n";
        }
        else if(x == 3)
        {
            test.insertionSortView(1);
        }
        else if(x == 4)
        {
            string s;
            cout << "Please enter your car's id\n";
            cin >> s;
            test.remove(s);
            cout << "\n";
        }
        else{
            if(x > 5)
            {
                cout << "Please press a number between 1-5" << "\n";
                cout << "\n";
                cout << "\n";
            }
        }
        
    }while(x != 5);*/

	return 0;
}


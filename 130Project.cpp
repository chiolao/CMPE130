// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// the most things we can store in the table
const int MAX_SIZE = 15;
const int MAX_SIZE2 = 20;
int currentSize =0;

// a product with a code & price
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
	void insert(cars p)
    {
        if(currentSize == MAX_SIZE)
        {
            cout << "garage is full" << endl;
        }
        else
        {
            
        
            // hash the product
            bool test;
            int index = hash(p.distance);
        
            // make a new node at the start of this list
            Node* node = new Node;
            node->car = p;
            //node->next = inventory[index];
        
            //cout << "" <<floor << endl;
       
            if(inventory[index] == NULL || inventory[index]->del == true)
            {
                inventory[index] = node;
                currentSize++;
            }
            else
            {
                while((inventory[index] != NULL) || (inventory[index]->del != true))
                {
                    index++;
                }
                inventory[index] = node;
                currentSize++;
            }
        
        
            cout << "Inserted "<<p.license << " distance ="<< p.distance << " at parking number" << index<<endl;
            currentSize ++ ;
                
        }
	}


	// lookup a product's price
    bool search (string key)
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
        
       if (inventory[index]->car.license == s)
        {
         
            cout <<inventory[index]->car.license << "is found" << endl;
            return true;
        
        }
        else
        {
            cout<< "You car is not in garage " << endl;
            return false;
        }
      
            
    }
	
	

	// hash a string into am index
	int hash(int dist) {
        int value = dist % MAX_SIZE;
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
        Node()
        {
            car = cars();
            next = NULL;
            del = false;
        }
		cars car;
		Node* next;
        bool del;

	};

	// the products are all stored in an array
    
	Node* inventory[MAX_SIZE];
    //Node* inventory2[MAX_SIZE2];
    //Node* floor[3];
};

// main program
int main() {
	HashTable table1, table2, table3, table4, table5;

    table1.insert(cars("car1", 5));
     table1.insert(cars("car2", 7));
     table1.insert(cars("car3", 6));
     table1.insert(cars("car4", 1));
   
  
	return 0;
}


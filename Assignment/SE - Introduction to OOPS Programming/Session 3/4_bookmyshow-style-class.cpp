/*
Simulate a BookMyShow ticket booking by creating a Ticket class that prints 'Saving your ticket...' in its destructor. 
Create and delete a Ticket object to demonstrate the destructor lifecycle. 
Hint: Use the __del__ method (Python) or ~Ticket() (C++) to define the destructor.
*/
#include <iostream>
#include <string>
using namespace std;

class Ticket {
	int ID;
	string movieName;
	string seatNo;
	float price;
	
	public:
		Ticket(int ID, string movieName, string seatNo, float price) : ID(ID), movieName(movieName), seatNo(seatNo), price(price) { 
			cout << "Creating your ticket...\n";
		}
		
		~Ticket() {
			cout << "Saving your ticket...\n";
		}
};

int main() {
	// Creating object in dynamic memory
	Ticket *t1 = new Ticket(101, "Dhurandhar", "A12", 250);
	
	// Deleting the object manually, beacuse we've created it in dynamic memory
	delete t1;
	
	return 0;
}

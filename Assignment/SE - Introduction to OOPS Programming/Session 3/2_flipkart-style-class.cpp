/*
Build a class Product for a Flipkart-style app with a parameterized constructor that takes productName, price, and rating 
as arguments and displays all details using a displayInfo() method.
*/
#include <iostream>
#include <string>
using namespace std;

class Product {
	string productName;
	int price;
	float rating;
	
	public:
		// Parameterized constructor
		Product(string productName, int price, float rating) : productName(productName), price(price), rating(rating) { }
		
		void displayInfo() {
			cout << "Product name: " << productName << "\n";
			cout << "Product price: Rs." << price << "\n";
			cout << "Product rating: " << rating << "\n";
		}
};

int main() {
	Product p1("Iphone 17 Pro Max (128 GB)", 90000, 4.2);
	p1.displayInfo();
	
	return 0;
}

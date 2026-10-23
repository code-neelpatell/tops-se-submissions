/*
Write a function in Java or Python that simulates a Flipkart-style search: overload a method searchProduct() to allow searching 
by product name or by product name and category. Demonstrate both usages with sample data.
*/
#include <iostream>
#include <string>
using namespace std;

class Product {
	string name;
	string categoryName;
	
	public:
		Product() : name(""), categoryName("") { }
		
		void create(string name, string categoryName) {
			this->name = name;
			this->categoryName = categoryName;
		}
		
		string getName() const {
			return name;
		}
		
		string getCategoryName() const {
			return categoryName;
		}
		
		void showDetails() const {
			cout << "---- Product Info ----\n";
			cout << "Name: " << name << "\n";
			cout << "Category: " << categoryName << "\n";
		}
};

class Inventory {
	Product products[10];
	int count;
	
	public:
		Inventory() : count(0) { }		
		
		void addProduct(string name, string categoryName) {
			if(count >= 10) {
				cout << "The inventory limit exceeded, You can't add more products.\n";
				return;	
			}
			
			products[count].create(name, categoryName);
			count++;
			cout << "New product added in inventory.\n";
		}	
		
		void searchProduct(string name) const {
			bool isFound = false;
			
			for(int i=0; i<count; i++) {
				if(products[i].getName() == name) {
					products[i].showDetails();
					isFound = true;
				}
			}
			
			if(!isFound) {
				cout << "No product found!\n";
			}
		}
		
		void searchProduct(string name, string categoryName) const {
			bool isFound = false;
			
			for(int i=0; i<count; i++) {
				if((products[i].getName() == name) && (products[i].getCategoryName() == categoryName)) {
					products[i].showDetails();
					isFound = true;
				}
			}
			
			if(!isFound) {
				cout << "No product found!\n";
			}
		}
};


int main() {
	Inventory inv;
	// Add products
	inv.addProduct("iPhone 16", "Electronics");
	inv.addProduct("Samsung Galaxy S25", "Electronics");
	inv.addProduct("Nike Air Max", "Footwear");
	inv.addProduct("Adidas Ultraboost", "Footwear");
	inv.addProduct("Levi's Jeans", "Clothing");
	cout << "\n";
	
	// Search product with name
	inv.searchProduct("Laptop"); // No product found
	cout << "\n";
	inv.searchProduct("iPhone 16");
	cout << "\n";
	
	// Search product with name & catgory name
	inv.searchProduct("iPhone 16", "Clothing"); // No product found
	cout << "\n";
	inv.searchProduct("Nike Air Max", "Footwear");
	cout << "\n";
		
	return 0;
}


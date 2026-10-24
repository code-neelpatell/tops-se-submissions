// Build a Flipkart-style wishlist tracker: ask the user to enter 3 product names and prices, save them to a file called wishlist.txt, 
// then read the file and display each product with its price.
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Product {
	string name;
	int price;
};	

class Whishlist {
	Product products[3];
	int count;
	
	public:
		Whishlist() : count(0) { }
		
		int getLimitCount() {
			return 3;
		}
		
		void addProduct(Product newProduct) {
			// Check if name is empty
			if(newProduct.name.empty()) {
				cout << "Product name can't be empty.\n";
				return;
			}
			// Check if price is zero or negative
			if(newProduct.price <= 0) {
				cout << "Invalid product price.\n";
				return;
			}
			// Check if limit is exceeding
			if(count >= 3) {
				cout << "Whishlist limit is exceeded, You can't add more products.\n";
				return;
			}
			
			// Add record
			products[count] = newProduct;
			count++;
			
			cout << "Product added in whishlist.\n";
		}	
		
		void saveFile() {
			if(count <= 0) {
				cout << "There's no data in whishlist to add in file.\n";
				return;
			}
			
			// Open file for writing
			ofstream writeFile("wishlist.txt");
			// Check if file opened successfully
			if(!writeFile.is_open()) {
				cout << "Error in opening file for writing.\n";
				return;
			}
			
			// Write data in file
			for(int i=0; i<count; i++) {
				writeFile << products[i].name << "," << products[i].price << "\n";
			}
			
			// Close file
			writeFile.close();
			cout << "All whishlisted products added in file.\n";
		}
		
		void readFile() {
			// Open file for reading
			ifstream readFile("wishlist.txt");
			string line;
			
			// Check if file opened successfully
			if(!readFile.is_open()) {
				cout << "Error in opening file for reading.\n";
				return;
			}
			
			// Reading data from file
			cout << "Reading data from file.\n";
			while(getline(readFile, line)) {
				// Converts string into a stream, to get data from it like input
				stringstream ss(line);
				string name, priceStr;

				// Extract values from line saperated by comma(,)
				if(getline(ss, name, ',') && getline(ss, priceStr, ',')) {
					cout << "Name: " << name << " | Price: Rs." << priceStr << "\n";
				}
			}
			
			// Close file
			readFile.close();
		}
};

int main() {
	Whishlist list;
	Product product;
	
	// Input and share data to add
	cout << "Add products in Whishlist.\n";
	for(int i=0; i<list.getLimitCount(); i++) {
		cout << "Product " << i+1 << "-\n";

		cout << "Enter name: ";
		getline(cin, product.name);

		cout << "Enter price: Rs.";
		cin >> product.price;
		cin.ignore();
		
		list.addProduct(product);

		cout << "\n";
	}
	
	// Save data into file
	list.saveFile();
	cout << "\n";
	
	// Read data from file
	list.readFile();
	cout << "\n";
	
	return 0;
}

/*
Imagine a Flipkart-like app: create an abstract class Product with an abstract method upload(). 
Then, create two subclasses, Electronics and Clothing, that each implement the upload() method to print a different upload message.
*/
#include <iostream>
using namespace std;

class Product {
	public:
		virtual void upload() = 0;
};

class Electronics : public Product {
	public:
		void upload() override {
			cout << "Product uploaded in 'Electronics' category.\n";
		}
};

class Clothing : public Product {
	public:
		void upload() override {
			cout << "Product uploaded in 'Clothing' category.\n";
		}
};

int main() {
	Electronics product1;
	Clothing product2;
	
	// Calling abstracted method
	product1.upload();
	product2.upload();
	
	return 0;
}

/*
Create a Java class called PaymentProcessor with two overloaded methods processPayment(): one that takes only an amount, 
and one that takes amount and a coupon code. Print which version is called and the final amount in each case.
*/
#include <iostream>
#include <string>
using namespace std;

class PaymentProcessor {
	public:
		void processPayment(float amount) {
			cout << "Called method: With only amount.\n";
			cout << "Final amount: Rs." << amount << ".\n";
			cout << "\n";
		}
		
		void processPayment(float amount, string couponCode) {
			cout << "Called method: With amount and coupon code.\n";
			float finalAmount = amount;
			if(amount >= 500 && couponCode == "NEWUSER") {
				finalAmount -= 500;
			}
			
			cout << "Final amount: Rs." << finalAmount << ".\n";
			cout << "\n";
		}
};

int main() {
	PaymentProcessor processor;
	processor.processPayment(1000);
	processor.processPayment(1000, "NEWUSER");
	
	return 0;
}

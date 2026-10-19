/*
1. Create a class called FoodOrder with properties: orderId (number), restaurantName (string), and isDelivered (boolean). 
Write a member function markDelivered() that sets isDelivered to true and prints a message. Instantiate FoodOrder and call markDelivered().
2. Refactor your FoodOrder class so that the constructor takes an object as a parameter (with keys orderId, restaurantName, isDelivered) 
instead of separate arguments. Update your instantiation code to use this new constructor signature.
*/
#include <iostream>
#include <string>
using namespace std;

struct OrderInfo {
	int ID;
	string restaurantName;
	bool isDelivered;
};

class FoodOrder {
	int orderId;
	string restaurantName;
	bool isDelivered;
	
	public:
		FoodOrder(OrderInfo info) : orderId(info.ID), restaurantName(info.restaurantName) , isDelivered(info.isDelivered) { }
		
		void markDelivered() {
			isDelivered = true;
			cout << "Order marked as delivered.\n";
			cout << "\n";
		}
		
		void showDetails() {
			cout << "---- ORDER DETAILS ----\n";
			cout << "ID: " << orderId << "\n";
			cout << "Restaurant: " << restaurantName << "\n";
			cout << "Status: " << (isDelivered ? "Delivered" : "Not Delivered") << "\n";
			cout << "\n";
		}
};

int main() {
	struct OrderInfo info = {101, "Raipur Bajiya House", false};
	FoodOrder order(info);
	
	// Show order details
	order.showDetails();
	
	// Call method to mark order as delivered
	order.markDelivered();
	
	// Show order details after status updated
	order.showDetails();	
	
	return 0;
}

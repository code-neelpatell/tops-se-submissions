/*
Create a constant variable to store the GST rate (for example, 18%) and use it to calculate the final price of a Zomato order with a given base price.
Constraint: The GST rate must not be changeable after its initial assignment.
*/

#include<stdio.h>

int main() {
	const int GST_RATE = 18; // constant variable
	float order_price, final_price;
	
	printf("Enter order's base price: Rs.");
	scanf("%f", &order_price);
	
	final_price = order_price + ((order_price * GST_RATE)/100);
	
	printf("Final order price(GST included): Rs.%.2f", final_price);
	
	return 0;
}

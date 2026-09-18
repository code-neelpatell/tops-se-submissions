/*
Create a Flipkart discount calculator that asks the user for the total cart amount. 
Use nested if statements to check: if amount > 2000, apply 20% discount; else if amount > 1000, apply 10% discount; else, no discount. 
Print the final amount to pay. Hint: Use nested ifs to check each discount slab.
*/

#include<stdio.h>

int main() {
	float cart_amount, final_amount;
	
	printf("Enter your cart amount: Rs.");
	scanf("%f", &cart_amount);
	
	if(cart_amount > 2000)
		final_amount = cart_amount - ((cart_amount * 20) / 100); // apply 20% discount
	else {		
		if(cart_amount > 1000)
			final_amount = cart_amount - ((cart_amount * 10) / 100); // apply 10% discount
		else 
			final_amount = cart_amount;
	}
		
	printf("Your final amount to pay: Rs.%.2f", final_amount);
	
	return 0;
}

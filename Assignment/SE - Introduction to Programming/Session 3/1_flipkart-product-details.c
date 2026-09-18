/*
Declare variables for a Flipkart product: productName (as a string), price (float), and rating (double).
Assign sample values and print each variable with its data type.
*/

#include<stdio.h>

int main() {
	char productName[] = "Apple iPhone 15";
	float price = 59900.0;
	double rating = 4.6;
	
	printf("Flipkart product:");
	printf("\nName: %s", productName);
	printf("\nPrice: %.2f", price);
	printf("\nRating: %.1lf", rating);
	
	return 0;
}

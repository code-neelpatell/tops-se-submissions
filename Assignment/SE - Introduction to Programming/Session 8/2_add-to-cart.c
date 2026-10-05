/*
Create a function addToCart that takes a shopping cart array and a product name, adds the product to the cart, 
and prints the updated cart. Demonstrate how passing the cart array by reference allows changes to persist outside the function.
Hint: In languages like JavaScript, arrays are passed by reference. In C/C++, use pointers for reference behavior.
*/
#include<stdio.h>
#include<string.h> 

#define CART_LIMIT 10
#define PRODUCT_NAME_LENGTH 50

void addToCart(char [][PRODUCT_NAME_LENGTH], const char []);

int main() {
	char cart[CART_LIMIT][PRODUCT_NAME_LENGTH] = { "Apple", "Milk", "Bread" };
	char product_name[PRODUCT_NAME_LENGTH];
	
	printf("==== CART DETAILS ====\n");
	for(int i=0; cart[i][0]!='\0'; i++) {
		printf("%d. %s\n", i+1, cart[i]);
	}
	printf("\n");
	
	printf("Enter a new product name: ");
	fgets(product_name, PRODUCT_NAME_LENGTH, stdin);
	
	product_name[strcspn(product_name, "\n")] = '\0'; // Remove the '\n'(newline char) got from "fgets" from the input
	printf("\n");
	
	addToCart(cart, product_name);
	
	printf("==== UPDATED CART DETAILS ====\n");
	for(int i=0; cart[i][0]!='\0'; i++) {
		printf("%d. %s\n", i+1, cart[i]);
	}
	
	return 0;
}

void addToCart(char cart[][PRODUCT_NAME_LENGTH], const char product_name[]) {
	// Get cart's next empty position
	int cart_count = 0;
	while(cart[cart_count][0] != '\0') {
		cart_count++;
	}

	// Add the product into cart	
	strcpy(cart[cart_count], product_name);
}



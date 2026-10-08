// Copy the string 'Flipkart' into another string variable called shoppingApp using strcpy(), then print the value of shoppingApp.
// Hint:Make sure to declare enough space for the destination string.
#include<stdio.h>
#include<string.h>

int main() {
	char shoppingApp[30];
	
	strcpy(shoppingApp, "Flipkart");
	printf("Shopping App: %s\n", shoppingApp);
	
	return 0;
}

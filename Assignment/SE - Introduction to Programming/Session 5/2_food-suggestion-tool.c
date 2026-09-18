/*
Build a Zomato-style food suggestion tool: take the user's preferred meal time ('breakfast', 'lunch', 'dinner', or 'snack') 
and use a switch-case statement to suggest a popular dish for that time. If the input doesn't match any meal, suggest 'Try some fruits!'.
*/
#include<stdio.h>

int main() {
	int selection;
	
	printf("What kind of meal are you looking for?");
	printf("\n1. Breakfast");
	printf("\n2. Lunch");
	printf("\n3. Dinner");
	printf("\n4. Snacks");
	printf("\nSelect: ");
	scanf("%d", &selection);
	
	switch(selection) {
		case 1:
			printf("How about some Masala Dosa?");
			break;
		case 2:
			printf("How about some Paneer Biryani?");
			break;
		case 3:
			printf("How about some Butter Chicken?");
			break;
		case 4:
			printf("How about some Samosa?");
			break;
		default:
			printf("Try some fruits!");	
	}
	
	return 0;
}

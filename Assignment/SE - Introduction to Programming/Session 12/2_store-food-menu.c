// Create a structure called FoodItem to store Zomato-style menu data: itemName (string), price (float), and rating (float). 
// Initialize an array of 3 FoodItem variables with real menu items and display their details using a loop.
#include<stdio.h>

struct FoodItem {
	char itemName[50];
	float price;
	float rating;
};

int main() {
	struct FoodItem item[3] = {
		{"Paneer Chilli Dry", 450, 3.9},
		{"Veg. Manchurian Dry", 390, 5.0},
		{"Bhindi Masala", 255, 4.9}		
	};
	int len = sizeof(item) / sizeof(item[0]);
		
	printf("==== FOOD MENU ====\n");	
	for(int i=0; i<len; i++) {
		printf("Name: %s\n", item[i].itemName);
		printf("Price: Rs.%.2f\n", item[i].price);
		printf("Rating: %.1f\n", item[i].rating);
		printf("\n");
	}
	
	return 0;
}


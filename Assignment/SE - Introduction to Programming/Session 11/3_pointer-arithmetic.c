// Given an array of 5 order amounts (e.g., Zomato orders), use a pointer to iterate through the array and 
// print each amount along with its memory address. Hint: Use pointer arithmetic to move to the next element.
#include<stdio.h>

int main() {
	int order_amounts[] = {345, 908, 1340, 5690, 78};
	int len = sizeof(order_amounts) / sizeof(order_amounts[0]);
	int *ptr = order_amounts; 
	// order_amount = &order_amount. 
	// Pointer points the first index of the array
	// The array name itself represents the address of its first index
		
	for(int i=0; i<len; i++) {
		printf("Memory Address: %u, Amount: Rs.%d\n", ptr, *ptr);
		ptr++; // This increament will shift the pointer to the array's next index	
	}
	
	return 0;
}


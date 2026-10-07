// Declare a 1D array called dailySteps with 7 elements to store your step count for each day of the week, 
// assign sample values, and print each value using a loop.
#include<stdio.h>

void display_report(const int [], int); // accepting array as const, so the function can't modify it.

int main() {
	int dailySteps[] = {1200, 6700, 2345, 8765, 1290, 10234, 12987};
	int arr_length = sizeof(dailySteps) / sizeof(dailySteps[0]);
	
	display_report(dailySteps, arr_length);
	
}

void display_report(const int arr[], int length) {
	printf("Last week's walking report\n");
	printf("--------------------------\n");
	for(int i=0; i<length; i++)
		printf("Day %d: %d steps\n", i+1, arr[i]);
}

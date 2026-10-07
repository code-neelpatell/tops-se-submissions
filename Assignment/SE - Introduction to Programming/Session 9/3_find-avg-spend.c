// Build a function that takes a 1D array of 7 integers representing your daily Zomato order amounts and calculates 
// the average spend for the week. Hint: Use a loop to sum the values, then divide by the array length.
#include<stdio.h>

float findAvgSpend(const float [], int);
	
int main() {
	float dailySpend[] = {1234.67, 3459.04, 980, 87.45, 1289.0, 457.23, 867};
	int length = sizeof(dailySpend) / sizeof(dailySpend[0]);

	float avgSpend = findAvgSpend(dailySpend, length);
	printf("The average spend of last week on Zomato: Rs.%.2f\n", avgSpend);
	
	return 0;
}

float findAvgSpend(const float arr[], int length) {
	float sum=0;
		
	for(int i=0; i<length; i++) {
		sum += arr[i];
	}
	
	return sum/length;
}


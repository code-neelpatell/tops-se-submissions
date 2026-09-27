/*
Create a pattern that prints a pyramid of stars (*) with 6 rows, centered like the loading animation you see on BookMyShow 
when a page is loading. Hint: Use spaces to align the stars in the center for each row.
*/

#include<stdio.h>

int main() {
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=6-i; j++) {
			printf(" ");
		}
		for(int k=1; k<=i; k++) {
			printf("* ");
		}
		printf("\n");
	}
	
	return 0;
}

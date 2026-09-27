/*
Write code using nested loops to print a pattern of alternating 0s and 1s in a grid, like the checkered background seen in some 
Spotify playlist covers (e.g., for a 4x4 grid, alternate 0 and 1 in each cell).
*/

#include<stdio.h>

int main() {
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++){
			printf("%d ", (i+j)%2);
		}
		printf("\n");
	}
	
	return 0;
}

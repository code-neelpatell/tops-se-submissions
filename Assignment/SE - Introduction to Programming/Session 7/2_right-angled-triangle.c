/*
Build a right-angled triangle pattern using nested loops, where each row displays increasing numbers starting from 1,
similar to how a leaderboard on a gaming app shows rank numbers.
*/

#include<stdio.h>

int main() {
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=i; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
	
	return 0;
}

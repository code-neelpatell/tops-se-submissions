/*
Use nested for loops to print a grid of emojis representing a 5x5 Instagram post feed, where each cell shows a ??(camera) symbol.
Note: Beacuse the system doesn't support the emoji, this program is using * symbol.
*/

#include<stdio.h>

int main() {
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=5; j++) {
			printf("* ");
		}
		printf("\n");
	}
		
	return 0;
}

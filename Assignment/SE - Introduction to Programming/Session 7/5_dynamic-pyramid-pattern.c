// Modify your pyramid pattern code to accept the number of rows as user input, so the user can set the height of the pyramid before printing.

#include<stdio.h>

int main() {
	int n;
	
	printf("Select height of pyramid (in rows): ");
	scanf("%d", &n);
	printf("\n");
	
	if(n<=0) {
		printf("Height must be greater than 0!\n");
		return 1;
	}	
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n-i; j++) {
			printf(" ");
		}
		for(int k=1; k<=i; k++) {
			printf("* ");
		}
		printf("\n");
	}
	
	return 0;
}

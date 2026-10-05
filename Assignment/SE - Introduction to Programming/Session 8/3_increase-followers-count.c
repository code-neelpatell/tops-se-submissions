/*
Write two functions: increaseFollowersByValue and increaseFollowersByReference. 
Each should take a followers count and add 1000 to it, but one should use pass-by-value and the other pass-by-reference. 
Show how the original followers count changes (or doesn't) after calling each function.
*/
#include<stdio.h>

void increaseFollowersByValue(int);
void increaseFollowersByReference(int *);

int main() {
	int followers_count = 3460;

	printf("Initial Followers: %d\n", followers_count);
	
	// Passing variable value
	increaseFollowersByValue(followers_count);		
	printf("After function call (Pass by Value), Followers: %d\n", followers_count);

	// Passing variable address/reference
	increaseFollowersByReference(&followers_count);		
	printf("After function call (Pass by Reference), Followers: %d\n", followers_count);	

	return 0;
}

void increaseFollowersByValue(int count) {
	count += 1000;
}

void increaseFollowersByReference(int *count) {
	*count += 1000;
}

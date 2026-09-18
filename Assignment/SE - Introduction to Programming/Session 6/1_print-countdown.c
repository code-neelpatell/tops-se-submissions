// Write a program that prints the numbers from 10 down to 1 using a for loop, similar to a countdown timer.
#include<stdio.h>

int main() {
	
	// condition => i, when i becomes 0 => the condition becomes false => exit the loop
	for(int i=10; i; i--)
		printf("%d\n", i);
	
	return 0;
}

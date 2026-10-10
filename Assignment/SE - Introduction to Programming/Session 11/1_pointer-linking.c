// Declare an integer variable called likes and a pointer variable called ptrLikes; assign likes a value, point ptrLikes to likes, 
// and print both the value and the address stored in ptrLikes.

#include<stdio.h>

int main() {
	int likes;
	int *ptrLikes = NULL;
	
	likes = 450;
	ptrLikes = &likes;
	
	printf("Value at pointer: %d\n", *ptrLikes);
	printf("Address at the pointer: %u\n", ptrLikes);

	return 0;
}

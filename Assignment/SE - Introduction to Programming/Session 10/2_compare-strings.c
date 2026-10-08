// Take input for two usernames (as strings) and compare them using strcmp(). Display whether they are the same or different.
#include<stdio.h>
#include<string.h>

int main() {
	char username1[30], username2[30];

	printf("Enter username 1: ");
	scanf("%s", username1); // When we input a string we don't need to write '&' with variable, it automatically passed the address
	printf("Enter username 2: ");
	scanf("%s", username2);
	
	if(strcmp(username1, username2)==0)
		printf("Both strings are same.\n");
	else
		printf("Both strings are different.\n");
	
	return 0;
}

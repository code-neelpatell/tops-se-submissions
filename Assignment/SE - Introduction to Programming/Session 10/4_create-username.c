// Build a small script that takes the user's full name as input and creates a username by copying only the first 5 characters using strcpy(). 
// Print the generated username. Constraint: If the name is shorter than 5 characters, use the full name as the username.
#include<stdio.h>
#include<string.h>

void remove_space(char []);

int main() {
	char fullName[30];
	char username[6]; // Size needsa to be 6 (5 chars + 1 null char)
	
	printf("Enter full name: ");
	gets(fullName);
	remove_space(fullName);
	
	fullName[5] = '\0'; // putting null char at 5th index, so techincally the string will end here and length will be 5 chars
	strcpy(username, fullName);
	printf("Username: %s", username);
	
	return 0;
}

void remove_space(char str[]) {
	// Removing the spaces from the original string, so it won't get copied in username
	int len = strlen(str);
	
	for(int i=0; i<len; i++) {
		if(str[i] == ' ') {
			for(int j=i; j<len-1; j++) {
				str[j] = str[j+1];			
			}
		len--;
		}
	}
	str[len] = '\0';
}

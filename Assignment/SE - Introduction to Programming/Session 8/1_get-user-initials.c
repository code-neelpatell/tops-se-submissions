/* 
Declare a function called getUserInitials that takes a user's full name (like 'Virat Kohli') and returns their initials 
in uppercase (e.g., 'VK'). Call this function with your favorite cricketer's name and print the result. 
*/
#include<stdio.h>

int get_string_length(const char[]);
void getUserInitials(const char[], int, char[]);

int main() {
	char name[50];
	char user_initials[30];
	int arr_size = sizeof(name) / sizeof(name[0]);
	int name_length;
	
	printf("Enter your favorite cricketer's name: ");
	fgets(name, arr_size, stdin); // Get the string output with "space allowed"
	printf("\n");
	
	name_length = get_string_length(name);
	getUserInitials(name, name_length, user_initials);
	printf("Name initials: %s", user_initials);
	
	return 0;
}

int get_string_length(const char name[]) {
	int i=0;
	while(name[i]!='\0' && name[i]!='\n') {
		i++;
	}
	return i;
}

void getUserInitials(const char name[], int name_length, char user_initials[]) {
	int initial_index = 0;
	// Find and store the name initials
	for(int i=0; i<name_length-1; i++) {
		if(i==0 && name[i] != ' ') {
			user_initials[initial_index] = name[i];
			initial_index++;
			continue;
		}
		if(name[i] == ' ') {
			if(name[i+1] != ' ') {
				user_initials[initial_index] = name[i+1];
				initial_index++;
			}
		}
	}
	
	user_initials[initial_index] = '\0';
	
	// Convert initials into uppercase
	for(int i=0; user_initials[i]!='\0'; i++) {
		if(user_initials[i]>='a' && user_initials[i]<='z') {
			user_initials[i] -= 32;
		}
	}
}

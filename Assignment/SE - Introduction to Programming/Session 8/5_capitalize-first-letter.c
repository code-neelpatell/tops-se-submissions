/*
Declare a function called getUserInitials that takes a user's full name (like 'Virat Kohli') and returns their initials 
in uppercase (e.g., 'VK'). Call this function with your favorite cricketer's name and print the result. 

Refactor an existing function you wrote above to make it reusable for both product names and usernames 
(for example, a function that capitalizes the first letter of any string).
Constraint: The refactored function should work for any string input, not just a specific use case.
*/ 
#include<stdio.h>

void remove_trailing_newline(char[]);
int get_str_length(const char []);
void capitalizeStr(char [], int);

int main() {
	char str[50];
	int arr_size = sizeof(str) / sizeof(str[0]);
	int length;
	
	printf("Enter text: ");
	fgets(str, arr_size, stdin);
	remove_trailing_newline(str);
	length = get_str_length(str);
	
	
	capitalizeStr(str, length);
	printf("Output: %s\n", str);
	
	return 0;
}

void remove_trailing_newline(char str[]) {
	int i=0;
	while(str[i]!='\0' && str[i]!='\n') i++;

	if(str[i] == '\n') 
		str[i] = '\0';
}

int get_str_length(const char str[]) {
	int i=0;
	while(str[i]!='\0' && str[i]!='\n')
		i++;
	return i;
}

void capitalizeStr(char str[], int n) {
	// Convert first char in uppercase
	if(str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32; 
		
	// Convert rest of char in lowercase
	for(int i=1; i<n; i++) {
		if(str[i]>='A' && str[i]<='Z')
			str[i] += 32;
	}
}

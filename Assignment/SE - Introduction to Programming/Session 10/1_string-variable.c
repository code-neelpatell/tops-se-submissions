// Declare a string variable called songTitle and assign it the value 'Tum Hi Ho'. Print the length of the string using strlen().
#include<stdio.h>
#include<string.h> // Include library to access string related functions i.e. strlen()

int main() {
	char songTitle[] = "Tum Hi Ho";
	
	printf("String: %s\n", songTitle);
	printf("Length: %d", strlen(songTitle));
	
	return 0;
}

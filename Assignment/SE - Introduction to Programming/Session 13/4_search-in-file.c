// Write a program that reads all song names from playlist.txt and prints only those that contain the word 'love' (case-insensitive).
// Hint: Use the 'in' keyword or equivalent string method for filtering.
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
	char str[100], lower_str[100];
	char search_word[] = "love"; //keep the string in lowercase
	int search_result_count = 0;
	
	FILE *fptr = fopen("playlist.txt", "r");
	if(fptr == NULL) {
		printf("The file not found!\n");
		return 1;
	}

	printf("Searching songs with keyword '%s' in file:\n", search_word);
	printf("--------------------------------------------\n");
	while(fgets(str, sizeof(str), fptr) != NULL) {
		
		//converting string into lowercase - for case-insensitive search
		int i=0;
		for(i=0; i<strlen(str); i++) {
			lower_str[i] = tolower(str[i]);
		}
		lower_str[i] = '\0';
		
		if(strstr(lower_str, search_word) != NULL) {
			printf("%s", str);
			search_result_count++;
		}		
	}
	
	if(search_result_count == 0) 
		printf("No result found!\n");
	
	fclose(fptr);
	return 0;
}

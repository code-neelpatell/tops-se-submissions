// Open playlist.txt in read mode (r) and display each song name on a separate line in the console.
#include<stdio.h>

int main() {
	char str[100];
	FILE *fptr = fopen("playlist.txt", "r");
	if(fptr == NULL) {
		printf("The file not found!\n");
		return 1;
	}
	
	printf("Reading data from file:\n");
	printf("-----------------------\n");
	while(fgets(str, sizeof(str), fptr) != NULL) { // Run untill the end of file
		printf("%s", str);
	}
	
	fclose(fptr);
	return 0;
}

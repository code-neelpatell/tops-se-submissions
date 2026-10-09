// Add two more song names to playlist.txt without deleting the existing ones by opening the file in append mode (a).
#include<stdio.h>

int main() {
	char fav_songs[][100] = {"Aur Kya Chahiye - By Paresh Pahuja", "Alfaz - By Hamza Malik & Zain Zohaib"};
	int arr_len = sizeof(fav_songs)/sizeof(fav_songs[0]);
	
	FILE *fptr = fopen("playlis.txt", "a");
	if(fptr == NULL) {
		printf("Problem in opening file. Please try again later!\n");
		return 1;
	}
	
	for(int i=0; i<arr_len; i++) 
		fprintf(fptr, "%s\n", fav_songs[i]);
	printf("The data has been written on the file.\n");
	fclose(fptr);

	return 0;
}

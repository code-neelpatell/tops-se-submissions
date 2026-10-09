// Create a file called playlist.txt and write the names of your top 3 favorite songs from Spotify into it using write mode (w).
#include<stdio.h>

int main() {
	char fav_songs[][100] = {"Casca Thupka - By Yo Yo Honey Singh", "Moonlight - By Yo Yo Honey Singh ft. Priceless", "Banger - By Badshah"};
	int arr_len = sizeof(fav_songs) / sizeof(fav_songs[0]);
	
	FILE *fptr = fopen("playlist.txt", "w"); // Open file in write mode
	if(fptr == NULL) {
		printf("Problem in opening file. Please try again later!\n");
		return 1;
	}
	
	for(int i=0; i<arr_len; i++)
		fprintf(fptr, "%s\n", fav_songs[i]); // Write in file
	printf("The data has been written on the file.\n");
	fclose(fptr); // Close opened file
	return 0;
}

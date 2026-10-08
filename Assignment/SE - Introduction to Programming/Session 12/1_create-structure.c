// Declare a structure named Playlist to store details of a song: title (string), artist (string), and duration in seconds (integer). 
// Initialize one Playlist variable with your favorite song's details and print each field.
#include<stdio.h>

struct Playlist {
	char title[50];
	char artist[30];
	int duration;
};

int main() {
	struct Playlist p1 = { "Casa Tupka Anthemo", "Yo Yo Honey Singh" , 183 };

	printf("==== Fav. song details ====\n");
	printf("Title: %s\n", p1.title);
	printf("Artist: %s\n", p1.artist);
	printf("Duration: %d seconds\n", p1.duration);
	
	return 0;
}

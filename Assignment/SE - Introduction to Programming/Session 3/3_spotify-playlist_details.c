/*
Write a program that stores your favorite Spotify playlist's name (string), total number of songs (int), and average song duration in minutes (float). 
Print all values in a single formatted sentence.
*/

#include<stdio.h>

int main() {
	char playlist_name[] = "Today's Top Hits";
	int total_songs_count = 50;
	float avg_song_duration = 3.45;
	
	printf("My favorite Spotify playlist is \"%s\", which has %d songs with an average duration of %.2f minutes.", playlist_name, total_songs_count, avg_song_duration);
	return 0;
}

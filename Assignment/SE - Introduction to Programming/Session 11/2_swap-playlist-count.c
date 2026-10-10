// Write a function swapPlaylistCounts(int *a, int *b) that swaps the number of songs in two Spotify playlists using pointers, 
// then call the function in main and print the swapped values.
#include<stdio.h>

void swapPlaylistCounts(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int playlist1_songs_count = 340;
	int playlist2_songs_count = 789;
	
	printf("Before swaping values:\n");
	printf("Playlist-1 songs: %d\n", playlist1_songs_count);
	printf("Playlist-2 songs: %d\n", playlist2_songs_count);
	
	swapPlaylistCounts(&playlist1_songs_count, &playlist2_songs_count);
	
	printf("\n");
	printf("After swaping values:\n");
	printf("Playlist-1 songs: %d\n", playlist1_songs_count);
	printf("Playlist-2 songs: %d\n", playlist2_songs_count);
	
	return 0;
}


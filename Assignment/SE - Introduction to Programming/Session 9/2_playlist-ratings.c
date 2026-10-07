// Create a 2D array called playlistRatings to store ratings for 3 Spotify playlists over 5 days (rows = playlists, columns = days). 
// Fill it with sample numbers and print the ratings for the second playlist.
#include<stdio.h>

int main() {
	float playlistRatings[][] = { {4.5, 4.2, 4.5, 4.9, 5.0}, {4.0, 3.6, 3.5, 2.9, 4.6}, {2.5, 3.2, 3.5, 2.9, 4.0} };
	
	int rows_count = sizeof(playlistRatings) / sizeof(playlistRatings[0]);
	int cols_count = sizeof(playlistRatings[0]) / sizeof(playlistRatings[0][0]);
	int selected_row_index = 1;
	
	printf("Playlist %d, last %d days ratings\n", selected_row_index+1, cols_count);
	printf("---------------------------------\n");
	for(int i=0; i<cols_count; i++) {
		printf("Day %d: %.1f\n", i+1, playlistRatings[selected_row_index][i]);
	}
	
	return 0;
}

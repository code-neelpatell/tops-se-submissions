// Define a nested structure called MovieShow for a BookMyShow-style app: Movie (string), Screen (integer), and a nested structure Time with hours and minutes (integers). 
// Create and initialize a MovieShow variable for any movie and print its details in the format 'Movie: X, Screen: Y, Time: HH:MM'.
#include<stdio.h>

struct ShowTime {
	int hours;
	int minutes;
};

struct MovieShow {
	char movie[100];
	int screen;
	struct ShowTime showTime;	
};

int main() {
	struct MovieShow show = { "Drishyam: The Conclusion", 3, { 19, 30 } };
	
	printf("==== MOVIE DETAILS ====\n");
	printf("Title: %s\n", show.movie);
	printf("Screen: %d\n", show.screen);
	printf("Time: %d:%d\n", show.showTime.hours, show.showTime.minutes);
	
	return 0;
}


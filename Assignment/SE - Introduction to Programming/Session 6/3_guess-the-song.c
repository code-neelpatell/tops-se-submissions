/*
Build a 'Guess the Song' game like Spotify — the program randomly picks a song name from a list and asks the user to guess it. 
Use a do-while loop so the user can keep guessing until they get it right.
Constraint: Use at least 3 song names of your choice.
*/
#include<stdio.h>
#include<stdlib.h> // For random number generator
#include<time.h> // Dependent of stdlib.h

int main() {
	int system_selection, user_selection, attempts = 0;

	srand(time(NULL)); // To give us different starting point everytime, starting point of generating random numers
	system_selection = (rand() % 5) + 1; // Pick random number from 1 to 5
	
	printf("==== GUESS THE SONGS ====");
	printf("\n1. Chaiyya Chaiyya");
	printf("\n2. Tum Hi Ho");
	printf("\n3. Kabira");
	printf("\n4. Kal Ho Naa Ho");
	printf("\n5. Apna Bana Le");
	printf("\n=================\n");

	do {
		printf("\nGuess which song I've selected (1-5): ");
		scanf("%d", &user_selection);
		
		if(user_selection<=0 || user_selection>5)  {
			printf("Invalid selection! Pick a number between 1 and 5.");
			continue; // Skip the below loop code and go for next iteration
		}
		else if(user_selection != system_selection) {
			printf("Nope, Wrong selection!");		
		}
		
		attempts++;
	} while(user_selection != system_selection);
	
	printf("\nCorrect! You took %d attempt(s).", attempts);
		
	return 0;
}

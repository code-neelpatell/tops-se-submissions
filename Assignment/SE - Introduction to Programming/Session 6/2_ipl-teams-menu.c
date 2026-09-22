/*
Create a menu-driven console app that lets the user: 1) View your favorite 3 IPL teams, 2) Add a new team, 3) Exit.
Use a while loop to keep showing the menu until the user chooses Exit. 
Hint: Use input() (or Scanner in Java) to get the user's choice each time.
*/

#include<stdio.h>
#include<string.h>

#define MAX_TEAMS 5
#define NAME_LENGTH 30

int main() {
	char teams[MAX_TEAMS][NAME_LENGTH] = {"CSK", "MI", "RCB"};
	int team_count=3, keep_going=1, input_choice;
	
	do{
		// Print menu
		printf("\n");
		printf("=== IPL MENU ===\n");
		printf("1. View Favorite Teams\n");
		printf("2. Add a New Team\n");
		printf("3. Exit\n");
		printf("Enter choice: ");
		
		// Get choice input
		scanf("%d", &input_choice);

		// Clear input buffer
		int c;
		while ((c = getchar()) != '\n' && c != EOF);		
		
		// Decide the operation
		switch(input_choice) {
			case 1:
				// Display fav. teams
				printf("Favorite Teams:\n");
				for(int i=0; i<team_count; i++) {
					printf("%d. %s\n", i+1, teams[i]);
				}
				printf("\n");
				break;
			case 2:
				// Check if teams count is exceeding
				if(team_count == MAX_TEAMS) {
					printf("You've exceeded limit, You can add maximum %d teams.\n", MAX_TEAMS);
					break;
				}
				// Add new team
				printf("Enter new team name: ");
				char team_name[NAME_LENGTH];
				fgets(team_name, NAME_LENGTH, stdin);
				// removes trailing newline from input
				team_name[strcspn(team_name, "\n")] = '\0';
				// Add the name into array
				strcpy(teams[team_count], team_name);
				team_count++;
				printf("New team added.\n");
				break;
			case 3:
				printf("Thank you for visiting.\n");
				keep_going = 0;
				break;
			default:
				printf("Invalid choice, Try again.\n");
		}		
	} while(keep_going);
	
	return 0;
}

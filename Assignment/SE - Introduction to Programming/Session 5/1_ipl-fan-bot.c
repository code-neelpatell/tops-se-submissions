/*
Create a simple IPL Fan Bot that takes your favorite IPL team name as input and uses if-else-if statements to print 
a unique cheer message for each team (e.g., 'Go Mumbai Indians!', 'Chennai Super Kings for the win!'). 
If the team is not recognized, print 'Team not found!'
*/

#include<stdio.h>

int main() {
	int selection;
	
	printf("IPL Teams 2026");
	printf("\n-----------------------");
	printf("\n1. Mumbai Indians");
	printf("\n2. Chennai Super Kings");
	printf("\n3. Gujarat Titans");
	printf("\n4. Royal Challengers Bengaluru");
	printf("\n5. Kolkata Knight Riders");
	printf("\n6. Rajasthan Royals");

	printf("\nSelect your fav. team: ");	
	scanf("%d", &selection);
	
	if(selection == 1)
		printf("\n\"Go Mumbai Indians!\"");
	else if(selection == 2)
		printf("\n\"CSK, let's bring home the win!\"");
	else if(selection == 3)
		printf("\n\"Come on Gujarat Titans, dominate!\"");
	else if(selection == 4)
		printf("\n\"RCB, play bold and win!\"");
	else if(selection == 5)
		printf("\n\"KKR, unleash the power!\"");
	else if(selection == 6)
		printf("\n\"Go Royals, rule the game!\"");
	else 
		printf("\nTeam not found!");
	return 0;
}

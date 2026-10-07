// Given a 2D array called cricketScores where each row represents an IPL match and columns represent runs scored by each team, 
// write code to print the highest score from each match.
#include<stdio.h>

int main() {
	int cricketScores[][2] = { {178, 189}, {120, 119}, {234, 250}, {189, 150}, {90, 108} };
	int rows = sizeof(cricketScores) / sizeof(cricketScores[0]);
	
	for(int i=0; i<rows; i++) {
		printf("Match-%d highest score: ", i+1);
		if(cricketScores[i][0] > cricketScores[i][1])
			printf("%d runs\n", cricketScores[i][0]);
		else
			printf("%d runs\n", cricketScores[i][1]);				
	}
	
	return 0;
}



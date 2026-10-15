/*
Task 1: Grade Band Checker
Build a console program that accepts a student's percentage score and prints their letter grade along with a short motivational message.
- Accept a float percentage value as user input using scanf().
- Assign a grade using if-else if: A (>= 90), B (>= 75), C (>= 60), D (>= 45), F (below 45).
- Print the assigned grade and a one-line message for each band (e.g., 'B — Good work! Keep pushing.').
- Handle invalid input: if the score is outside the range 0–100, print a clear error message and exit the program gracefully.
*/
#include<stdio.h>

int main() {
	float percentage;
	char grade;
	
	printf("Enter your percentage: ");

	// Handling invalid non-numeirc input
	if(scanf("%f", &percentage) != 1) {
		printf("Invalid input! Please enter a numeric percentage.\n");
		return 1;
	}
	// Handling invalid numeric input
	if(percentage<0 || percentage>100) {
		printf("Invalid percentage! Please enter a score between 0 and 100.");
		return 1;
	}
	
	// Assigning the grades and printing output
	if(percentage >= 90) {
		grade = 'A';
		printf("Your Grade: %c - Excellent work! Keep shining!\n", grade);
	}
	else if(percentage >= 75) {
		grade = 'B';
		printf("Your Grade: %c - Good work! Keep pushing!\n", grade);		
	}
	else if(percentage >= 60) {
		grade = 'C';		
		printf("Your Grade: %c - Nice effort! Keep improving!\n", grade);		
	}
	else if(percentage >= 45) {
		grade = 'D';
		printf("Your Grade: %c - You're making progress! Keep going!\n", grade);		
	}
	else {
		grade = 'F';
		printf("Your Grade: %c - Don't give up! Learn from mistakes and try again!\n", grade);
	}
	
	return 0;
}

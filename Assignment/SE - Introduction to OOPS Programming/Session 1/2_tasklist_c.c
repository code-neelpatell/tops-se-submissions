/* 
1. Write a simple C program tasklist_c.c that allows you to add up to 5 tasks (as strings) to a global array and print all tasks using a for loop.
2. Modify your tasklist_c.c to add a function markTaskDone(int index) that sets the selected task to 'DONE' in the array, then print the 
updated list. Hint:Use a separate status array or append ' - DONE' to the task string.
*/
#include<stdio.h>
#include<string.h>

#define TASK_LIMIT 5
#define TASK_LENGTH 100

char tasks[TASK_LIMIT][TASK_LENGTH];
int tasksStatus[TASK_LIMIT] = {0, 0, 0, 0, 0}; // Initialize with 0, to indicate not completed

void removeTrailingNewline(char []);
int getValidInput(const char [], int, int);
void addTasks();
void showTasks();
void markTaskDone(int);

int main() {
	// Add tasks
	addTasks();
	
	// Print all tasks
	showTasks();

	// Select task to mark as complete
	int selectedTaskIndex = getValidInput("Select task to mark as complete: ", 1, TASK_LIMIT) - 1;
	markTaskDone(selectedTaskIndex);
	
	// Print all tasks
	showTasks();
	
	return 0;	
}

void removeTrailingNewline(char str[]) {
    // Find the '\n' and replace it with a null-terminator '\0'	
	str[strcspn(str, "\n")] = '\0';
}

int getValidInput(const char prompt[], int min, int max) {
	int input, return_value;

	do {
		printf("%s", prompt);
		// Checks how many valid input got
		return_value = scanf("%d", &input);
		// Clear input buffer to avoid infinite loop
		int ch;
		while((ch = getchar()) != '\n' && ch != EOF);
		
		if(return_value != 1) {
			// If input is non-numeric
			printf("Invalid input, Try again!\n");
		} 
		else if(input<min || input>max) {
			// If input is outside of min and max boundry
			printf("Invalid input, Enter a number between %d and %d.\n", min, max);
		}
		else {
			// Return valid input
			return input;
		}
	} while(1);	
}

void addTasks() {
	printf("Create task list:\n");
	for(int i=0; i<TASK_LIMIT; i++) {
		printf("Enter task %d: ", i+1);
		fgets(tasks[i], TASK_LENGTH, stdin);
		removeTrailingNewline(tasks[i]);
	}
	printf("\n");	
}

void showTasks() {
	printf("Task List:\n");
	for(int i=0; i<TASK_LIMIT; i++) {
		printf("(%d) %s%s", i+1, tasks[i], tasksStatus[i]==1 ? " - DONE\n" : "\n");		
	}	
	printf("\n");
}

void markTaskDone(int index) {
	tasksStatus[index] = 1;
}

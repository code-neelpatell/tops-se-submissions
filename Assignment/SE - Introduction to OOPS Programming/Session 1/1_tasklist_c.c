// Write a simple C program tasklist_c.c that allows you to add up to 5 tasks (as strings) to a global array and print all tasks using a for loop.
#include<stdio.h>
#include<string.h>

#define TASK_LIMIT 5
#define TASK_LENGTH 100

char tasks[TASK_LIMIT][TASK_LENGTH];

void removeTrailingNewline(char []);

int main() {
	// Add tasks
	printf("Create task list:\n");
	for(int i=0; i<TASK_LIMIT; i++) {
		printf("Enter task %d: ", i+1);
		fgets(tasks[i], TASK_LENGTH, stdin);
		removeTrailingNewline(tasks[i]);
	}
	
	// Print all tasks
	printf("\n\n");
	printf("Task List:\n");
	for(int i=0; i<TASK_LIMIT; i++) {
		printf("(%d) %s\n", i+1, tasks[i]);
	}
}

void removeTrailingNewline(char str[]) {
    // Find the '\n' and replace it with a null-terminator '\0'	
	str[strcspn(str, "\n")] = '\0';
}

/*
Task 4: Personal Expense Logger
Build a menu-driven C program that lets a user log and view personal daily expenses, and saves all records to a text file on exit.
- Define a struct Expense with fields: category (char[30]) and amount (float). Allocate an array to store up to 10 Expense entries.
- Present a menu with 3 options: (1) Add Expense, (2) View All Expenses, (3) Save & Exit. Loop until the user selects option 3.
- In the View option, display all logged expenses in a formatted list and print the running total at the bottom.
- On exit (option 3), write all expense records to a file named expenses.txt using fprintf(), with one record per line in the 
format: category,amount
*/
#include<stdio.h>
#include<string.h>

#define EXPENSE_COUNT 10
#define CATEGORY_LENGTH 30
#define FILE_NAME "expenses.txt"

struct Expense {
	char category[CATEGORY_LENGTH];
	float amount;
};

int getIntInput(const char [], int, int);
float getAmountInput();
void removeTrailingNewline(char []);

int showMenu();
void addExpense(struct Expense [], int *);
void viewAllExpenses(const struct Expense [], int);
void saveAndExit(const struct Expense [], int, int *);

int main() {
	struct Expense expenses[EXPENSE_COUNT];
	int selection, keepGoing=1, addCount=0;
	
	do {
		selection = showMenu();
		printf("\n");
		
		switch(selection) {
			case 1: addExpense(expenses, &addCount); break;
			case 2: viewAllExpenses(expenses, addCount); break;
			case 3: saveAndExit(expenses, addCount, &keepGoing); break;
		}
		
		if(keepGoing) printf("\n");
	} while(keepGoing);
	
	return 0;
}

int getIntInput(const char prompt[], int min, int max) {
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
			printf("Invalid input. Enter a numeric value.\n");
		} 
		else if(input<min || input>max) {
			// If input is outside of min and max boundry
			printf("Wrong input. Expected value is between %d - %d.\n", min, max);
		}
		else {
			// Return valid input
			return input;
		}
	} while(1);		
}

float getAmountInput() {
	int min = 1, max = 999999;
	float input;
	int return_value;

	do {
		printf("Enter Amount: ");
		return_value = scanf("%f", &input);
		// Clear input buffer to avoid infinite loop
		int ch;
		while((ch = getchar()) != '\n' && ch != EOF);

		if(return_value != 1) {
			// If input is non-numeric
			printf("Invalid input. Enter a numeric value.\n");
		} 
		else if(input<min || input>max) {
			// If amount are outside the range of min and max
			printf("Invalid input. Enter an amount between %d and %d.\n", min, max);
		}
		else {
			// Return valid input
			return input;
		}
	} while(1);	
}

void removeTrailingNewline(char str[]) {
	str[strcspn(str, "\n")] = '\0'; 	
}

int showMenu() {
	printf("==== DAILY EXPENSE LOGGER ====\n");
	printf("(1) Add Expense\n");
	printf("(2) View All Expenses\n");
	printf("(3) Save & Exit\n");
	
	return getIntInput("Selection: ", 1, 3);
}

void addExpense(struct Expense expenses[], int *addCount) {
	printf("Add Expense\n");
	printf("-----------\n");

	// Cancel operation if daily logging limit is exceeding	
	if(*addCount >= EXPENSE_COUNT) {
		printf("You've exceeded the daily logging limit.\n");
		return;
	}
	
	int newExpenseIndex = *addCount;
	// Input category
	printf("Enter Category: ");
	fgets(expenses[newExpenseIndex].category, CATEGORY_LENGTH, stdin);
	removeTrailingNewline(expenses[newExpenseIndex].category);
	// Input amount
	expenses[newExpenseIndex].amount = getAmountInput();
	// Increase add count
	(*addCount)++;
	// Success message
	printf("New expense logged.\n");
}

void viewAllExpenses(const struct Expense expenses[], int addCount) {
	printf("All Logged Expenses\n");
	printf("-----------------\n");
	
	if(addCount <= 0) {
		printf("No Expenses to show.\n");
		return;
	} 
	
	float totalAmount=0;
	printf("%-25s %-10s\n","Category", "Amount");
	printf("----------------------------------\n");
	for(int i=0; i<addCount; i++) {
		printf("%-25s %-10.2f\n", expenses[i].category, expenses[i].amount);
		totalAmount += expenses[i].amount;	
	}
	printf("----------------------------------\n");
	printf("%-25s %-10.2f\n","Total", totalAmount);
}

void saveAndExit(const struct Expense expenses[], int addCount, int *keepGoing) {
	printf("Save & Exit\n");
	printf("-----------\n");
	
	if(addCount <= 0) {
		printf("No Expenses to store.\n");
		// Making loop condition false for exit
		*keepGoing = 0;		
		return;
	} 
	
	// Opening file
	FILE *fptr = fopen(FILE_NAME, "w");
	// Velidating any issue in opening file
	if(fptr == NULL) {
		printf("We're facing an issue in opening file!\n");
		return;
	}
	// Writing data in file
	for(int i=0; i<addCount; i++) {
		fprintf(fptr, "%s,%.2f\n", expenses[i].category, expenses[i].amount);
	}
	fclose(fptr);
	
	// Success message
	printf("All logged expenses are stored in file.\n");
	// Making loop condition false for exit
	*keepGoing = 0;
}

/* 
Student Productivity Tracker
----------------------------
Build a console-based Student Productivity Tracker that logs daily study hours across subjects for a full week, combining arrays, 
structures, functions, and file handling from Module 3 into a single working program.

- The program must be menu-driven with at least 3 options: (1) Log Today's Study Hours, (2) View Weekly Report, (3) Save & Exit.
- Define a struct StudyLog { char subject[40]; float hours[7]; } and create an array of at least 3 subject records.
- Write a function that calculates and displays the weekly total hours and daily average for each subject.
- Display a simple text-based progress chart: for each subject, print one filled dot (•) per hour studied that day (truncate to nearest integer).
- On exit, save all records to a file named productivity_log.txt using fprintf(), with each subject's name and 7 daily values written 
as a single comma-separated line.
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define SUBJECTS_LIMIT 3
#define FILE_NAME "productivity_log.txt"

const char DAY_NAMES[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
const char SUBJECT_NAMES[SUBJECTS_LIMIT][20] = {"C Programming", "Maths", "Physics"};

struct StudyLog {
	char subject[40];
	float hours[7];
};

int getIntInput(const char [], int, int);
char getCharInput(const char []);
float getHoursInput(const char []);
int showMenu();
int showDaysList();
void getLogData(struct StudyLog [], int);

void setDefaultData(struct StudyLog []);
void loadData(struct StudyLog []);
void addLog(struct StudyLog []);
void showReport(const struct StudyLog []);
void showProgressBar(const struct StudyLog []);
void saveAndExit(const struct StudyLog [], int *);

int main() {
	struct StudyLog subjects[SUBJECTS_LIMIT];
	int keepGoing=1, selection;
	
	// Load data from existing file or Assign default values
	loadData(subjects);
	
	do {
		// Input menu selection
		selection = showMenu();
		printf("\n");
		// Select the operation based on selection
		switch(selection) {
			case 1: addLog(subjects); break;
			case 2: showReport(subjects); break;
			case 3: saveAndExit(subjects, &keepGoing); break;
		}
		if(keepGoing) printf("\n\n");
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

char getCharInput(const char prompt[]) {
	char input;

	printf("%s", prompt);
	scanf("%c", &input);

	// Clear input buffer to avoid infinite loop
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF);
		
	return tolower(input);
}

float getHoursInput(const char subjectName[]) {
	int min = 0, max = 24;
	float input;
	int return_value;

	do {
		printf("%s: ", subjectName);
		return_value = scanf("%f", &input);
		// Clear input buffer to avoid infinite loop
		int ch;
		while((ch = getchar()) != '\n' && ch != EOF);

		if(return_value != 1) {
			// If input is non-numeric
			printf("Invalid input. Enter a numeric value.\n");
		} 
		else if(input<min || input>max) {
			// If hours are negative or greater then 24
			printf("Invalid input. Enter a value between %d and %d.\n", min, max);
		}
		else {
			// Return valid input
			return input;
		}
	} while(1);		
}

void setDefaultData(struct StudyLog subjects[]) {
	// Assign the default data to subjects array
	for(int i=0; i<SUBJECTS_LIMIT; i++) {
		// Assign subject name
		strcpy(subjects[i].subject, SUBJECT_NAMES[i]);
		// Assign -1 (indicating empty space) as each day's hours
		for(int j=0; j<7; j++) {
			subjects[i].hours[j] = -1;
		}
	}			
}

void loadData(struct StudyLog subjects[]) {
	// Assign the default data in array at start
	setDefaultData(subjects);
	
	// Open the file for reading
    FILE *fptr = fopen(FILE_NAME, "r");

	// Validating file opening status	
	if (fptr == NULL) {
        return;
    }
    
    char line[200]; // To store input during file read
    int i=0;
    
    // Read records until EOF or SUBJECTS_LIMIT is reached
    while(i < SUBJECTS_LIMIT && fgets(line, sizeof(line), fptr) != NULL) {
    	// Get the subject name before first comma
    	char *value = strtok(line, ",");
    	
    	// Skip the iteration if value is NULL
		if(value == NULL) {
    		continue;
		}
		
		// Assign subject name
		strcpy(subjects[i].subject, value);
		
		// Iterate for subject's 7 days hours data
		for(int j=0; j<7; j++) {
			// Get the next comma saperated value
			value = strtok(NULL, ",");
			
			if(value == NULL) {
				// Use -1 when value is missing
				subjects[i].hours[j] = -1;
			}
			else {
				// Convert the value into float
				subjects[i].hours[j] = atof(value);
			}
		}
		
		i++;
	}
	
	// Check if file is empty, then intialize the subjects with default values
	if(i == 0) {
		setDefaultData(subjects);
	}
	
	// Close the file
	fclose(fptr);	
}

int showMenu() {
	printf("==== STUDENT PRODUCTIVITY TRACKER ====\n");
	printf("(1) Log Today's Study Hours\n");
	printf("(2) View Weekly Report\n");
	printf("(3) Save & Exit\n");
	printf("\n");
	
	return getIntInput("Select option: ", 1, 3);
}

int showDaysList() {
	printf("Select day:\n");
	for(int i=0; i<7; i++) {
		printf("%d. %s\n", i+1, DAY_NAMES[i]);
	}
	printf("\n");
	
	return getIntInput("Enter day number: ", 1, 7);
}

void getLogData(struct StudyLog subjects[], int dayIndex) {
	float hoursLimit = 24;
	printf("Enter study hours for %s:\n", DAY_NAMES[dayIndex]);

	// Input study hours of day across all subjects
	for(int i=0; i<SUBJECTS_LIMIT; i++) {
		subjects[i].hours[dayIndex] = getHoursInput(subjects[i].subject);
		// Checking if the total hours are not more then 24
		if(hoursLimit - subjects[i].hours[dayIndex] < 0) {
			printf("Your today's study hours becoming more then 24 hours. Check and try again.\n");
			// Revise the last iteration for taking input again
			i--;
			continue;
		}
		// Calculating the total hours of the day
		hoursLimit -= subjects[i].hours[dayIndex];
	}
	printf("\n");
}

void addLog(struct StudyLog subjects[]) {
	int isUpdated = 0;
	
	printf("---- LOG NEW DAY ----\n");
	// Input day selection
	int selectedDayIndex = showDaysList() - 1;
	printf("\n");
	
	// Check if selected day alrady have a log
	if(subjects[0].hours[selectedDayIndex] != -1) {
		printf("You've already logged %s.\n", DAY_NAMES[selectedDayIndex]); 
		// Show current data
		for(int i=0; i<SUBJECTS_LIMIT; i++) {
			printf("%s: %.1f hours\n", subjects[i].subject, subjects[i].hours[selectedDayIndex]);
		}
		printf("\n");
		// Ask if user wants to update
		char res = getCharInput("You you want to update it?(y/n) ");
		if(res != 'y') {
			return;			
		}
		isUpdated = 1;
		printf("\n");
	}
	
	// Input the data and assign at selected day
	getLogData(subjects, selectedDayIndex);
	
	// Print success message
	if(isUpdated)	
		printf("Study hours logs updated successfully.\n");
	else
	printf("Study hours logged successfully.\n");
}

void showReport(const struct StudyLog subjects[]) {
	float weeklyTotal, dailyAvg;
	int loggedDays;

	printf("---- VIEW REPORT ----\n");
	for(int i=0; i<SUBJECTS_LIMIT; i++) {
		weeklyTotal = 0;
		loggedDays = 0;
		// Calculating total of subject hours
		for(int j=0; j<7; j++) {
			// Checking if the value is not empty
			if(subjects[i].hours[j] != -1) {
				loggedDays++;
				weeklyTotal += subjects[i].hours[j];				
			}
		}
		
		dailyAvg = (loggedDays == 0 ? 0 : weeklyTotal / loggedDays);
		// Printing subject's report
		printf("%s:\n", subjects[i].subject);
		printf("Weekly Total: %.1f hours\n", weeklyTotal);
		printf("Daily Average: %.1f hours\n", dailyAvg);
		printf("\n");	
	}
	
	// Call to show progress bar
	showProgressBar(subjects);
}

void showProgressBar(const struct StudyLog subjects[]) {
	int loggedHours;
	
	printf("---- PROGRESS BAR ----\n");	
	// Iterating through all days
	for(int i=0; i<7; i++) {
		printf("%s:\n", DAY_NAMES[i]);
		// Iterating through day's all subjects
		for(int j=0; j<SUBJECTS_LIMIT; j++) {
			printf("%s:", subjects[j].subject);
			// Check if the day is logged or not
			if (subjects[j].hours[i] == -1) {
			    printf(" [Not logged]");
			}
			else {
				loggedHours = subjects[j].hours[i];
				// Printing the points indicating subject's study hours
				for(int k=0; k<loggedHours; k++) {
						printf(" *");
				}				
			}
			// Go to newline for each subject
			printf("\n");
		}
		// Printing newline for each day
		printf("\n");
	}
}

void saveAndExit(const struct StudyLog subjects[], int *keepGoing) {
	printf("---- SAVE & EXIT ----\n");
		
	// Opening file
	FILE *fptr = fopen(FILE_NAME, "w");
	// Validating file opening status
	if(fptr == NULL) {
		printf("We're having an issue in opening file. Try again.\n");
		return;
	}
	
	// Iterating through all subjects
	for(int i=0; i<SUBJECTS_LIMIT; i++) {
		// Writing subject name
		fprintf(fptr, "%s,", subjects[i].subject);
		// Iterating through subjects's 7 days of hour logs 
		for(int j=0; j<7; j++) {
			// Writing hours
			if(j == 7-1)
				fprintf(fptr, "%.1f\n", subjects[i].hours[j]);
			else
				fprintf(fptr, "%.1f,", subjects[i].hours[j]);
		}
	}
	// Closing file
	fclose(fptr);
	
	// Print success message
	printf("Data has been stored in the file.\n");
	// Chaning the menu-loop condition value
	*keepGoing = 0;
}


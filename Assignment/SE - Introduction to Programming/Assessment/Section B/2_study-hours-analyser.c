/*
Task 2: Weekly Study Hours Analyser
Build a program that records a student's daily study hours for 7 days, stores them in an array, and generates a performance summary.
- Use a for loop to accept 7 float values (one per day) and store them in a float array.
- Calculate and print the weekly total, daily average, and the day number with the highest study hours.
- Print a simple visual bar for each day: the day number followed by one asterisk (*) per hour studied, 
truncated to the nearest integer (e.g., Day 3: ***).
- Reject and re-prompt for any day entry that is negative or greater than 24, before storing it in the array.
*/

#include<stdio.h>

float get_input(const char []);
float calc_weekly_total(const float [], int);
int find_highest_hours_index(const float [], int);

void get_study_hours(float [], int);
void show_summary(const float [], int);
void print_visual_bar(const float [], int);

int main() {
	float study_hours[7];
	int arr_len = sizeof(study_hours) / sizeof(study_hours[0]);
	
	get_study_hours(study_hours, arr_len);
	show_summary(study_hours, arr_len);
	print_visual_bar(study_hours, arr_len);
	
	return 0;
}

float get_input(const char prompt[]) {
	float input;

	do {
		printf("%s", prompt);
		if(scanf("%f", &input) != 1) {
			// If input is non-numeric
			printf("Invalid input, Try again!\n");
			// Clear input buffer to avoid infinite loop
			int ch;
			while((ch = getchar()) != '\n' && ch != EOF);
		} 
		else if(input<0 || input>24) {
			// If input is invalid - negative or > 24
			printf("Invalid input, Enter a number between 0 and 24.\n");
		}
		else {
			// Return valid input
			return input;
		}
	} while(1);
}

void get_study_hours(float study_hours[], int len) {
	printf("==== WEEKLY STUDY HOURS ANALYSER ====\n");
	char prompt[50];
	
	for(int i=0; i<len; i++) {
		snprintf(prompt, sizeof(prompt), "Enter Day-%d hours: ", i+1);
		study_hours[i] = get_input(prompt);
	}
	printf("\n");
}

float calc_weekly_total(const float study_hours[], int len) {
	float total = 0;
	for(int i=0; i<len; i++) {
		total += study_hours[i];		
	}
	return total;
}

int find_highest_hours_index(const float study_hours[], int len) {
	int index = 0;
	for(int i=1; i<len; i++) {
		if(study_hours[i] > study_hours[index]) {
			index = i;
		}
	}
	return index;
}

void show_summary(const float study_hours[], int len) {
	float weekly_total = calc_weekly_total(study_hours, len);
	float daily_avg = weekly_total / len;
	int highest_hours_index = find_highest_hours_index(study_hours, len);
	
	printf("==== REPORT ====\n");
	printf("Weekly Total: %.2f hours\n", weekly_total);
	printf("Daily Average: %.2f hours\n", daily_avg);
	printf("Highest Study on Day: %d, for %.2f hours\n", highest_hours_index+1, study_hours[highest_hours_index]);
	printf("\n");
}

void print_visual_bar(const float study_hours[], int len) {
	int hours_count;

	printf("==== VISUAL BAR ====\n");
	for(int i=0; i<len; i++) {
		printf("Day %d: ", i+1);
		hours_count = (int)study_hours[i];
		for(int j=0; j<hours_count; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
}


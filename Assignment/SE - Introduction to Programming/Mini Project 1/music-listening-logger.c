/*
1. Create a console-based application called Music Listening Logger that allows users to enter the number of minutes 
they listen to music each day for a week and stores the data in an array.
2. Add a menu-driven interface that allows users to log new listening minutes, view their weekly summary, or exit 
the application. Use a loop to display the menu repeatedly until the user selects the exit option.
3. Implement file handling to save daily music listening data in a file named music_log.txt whenever the user logs their listening minutes.
4. Add a feature that reads the saved data from music_log.txt and generates a weekly report displaying the total, 
average, and highest listening minutes for the week.
5. Add a reset option to the menu that clears the array and deletes the contents of music_log.txt. Ask the user 
for confirmation before deleting any data.
*/

#include<stdio.h>
#include<ctype.h>

#define DAYS_COUNT 7
#define MIN_DURATION 0
#define MAX_DURATION 1440
#define FILE_NAME "music_log.txt"

const char DAYS[DAYS_COUNT][10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

int validate_input(int, int, int);
int get_int_input(const char [], int, int);

void load_logs(int [], int *);
int get_menu_selection();
void add_log(int [], int *);
int write_data_file(const int []);
void show_summary(const int [], int);
void delete_all_data(int [], int *);

int main() {
	int menu_selection, add_count=0, keep_going=1;
	int listening_duration[7];

	// Load all the logs from file at program startup
	load_logs(listening_duration, &add_count);
	
	while(keep_going) {
		menu_selection = get_menu_selection();
		printf("\n");
		switch(menu_selection) {
			case 1:
				add_log(listening_duration, &add_count);
				break;
			case 2:
				load_logs(listening_duration, &add_count);
				show_summary(listening_duration, add_count);
				break;
			case 3:
				delete_all_data(listening_duration, &add_count);
				break;
			case 4:
				printf("Thank you for visiting.");
				keep_going = 0;
				break;
		}
		printf("\n\n");	
	}
	return 0;
}

void load_logs(int logs[], int *add_count) {
	FILE *fptr;
	int data, index=0;
	
	// Initialize the array
	*add_count = 0;
	for(int i=0; i<DAYS_COUNT; i++) {
		logs[i] = -1; // -1 indicates empty space			
	}
	
	fptr = fopen(FILE_NAME, "r");
	// If file doesn't exists
	if(fptr == NULL) {
		return;
	}
	
	// Load the file data into array
	while(index < DAYS_COUNT && fscanf(fptr, "%d", &data) == 1) {
		if(data==-1 || data>=MIN_DURATION && data<=MAX_DURATION) {
			logs[index] = data;			
			if(data != -1) {
				(*add_count)++;
			}
		}
		index++;
	}
	
	fclose(fptr);
}

int validate_input(int input, int min, int max) {
	if(input>=min && input<=max)
		return 1;
	else {
		printf("Invalid value, Please try again!\n");
		return 0;
	}
}

int get_int_input(const char prompt[], int min, int max) {
	int input, is_validated;

	do {
		printf("%s", prompt);
		// If we user inputs a character instead of digit, the scanf don't clears them up for the next time. 
		// So we need to do it to avoid infinit loop.
		if (scanf("%d", &input) != 1) {
            // scanf failed, clear the bad character(s) from buffer
            int ch;
			while ((ch = getchar()) != '\n' && ch != EOF) {	}
            printf("Invalid value, Please try again!\n");
            is_validated = 0;
            continue;
        }		
		is_validated = validate_input(input, min, max);
	} while(!is_validated);
	
	return input;	
}

int get_menu_selection() {
	printf("======= MUSIC LISTENING LOGGER =======\n");
	printf("Share your weekly listening duration.\n");
	printf("--------------------------------------\n");	
	printf("1. Log new entry\n");
	printf("2. Show weekly summary\n");
	printf("3. Delete all data\n");
	printf("4. Exit\n");

	return get_int_input("Enter your choice: ", 1, 4);
}

void add_log(int logs[], int *add_count) {
	int input_index;
	char prompt[15];
	
	printf("------- NEW ENTRY -------\n");
	input_index = get_int_input("Select day number(1-7): ", 1, DAYS_COUNT) - 1;
	// Check the selected day has any entry
	if(logs[input_index] != -1) {
		printf("You've already logged this day!\n");
		return;
	}
	
	// Add entry at selected day in array
	snprintf(prompt, sizeof(prompt), "%s: ", DAYS[input_index]);
	logs[input_index] = get_int_input(prompt, MIN_DURATION, MAX_DURATION);
	
	// Calling function for writing the stored data into file from array
	int file_status = write_data_file(logs);
	if(file_status == 1) {
		// We found issue in writing file, clear the last entry
		logs[input_index] = -1;
		return;
	}
	
	// Increasing the added entry count
	(*add_count)++;
	printf("You've logged a new day.\n");
}

int write_data_file(const int logs[]) {
	FILE *fptr = fopen(FILE_NAME, "w");
	
	// If we found any issue in creating or opening the file
	if(fptr == NULL) {
		printf("We're having an issue in the writing data, Please try again later!\n");
		return 1;
	}
	
	// Writing data in file from array
	for(int i=0; i<DAYS_COUNT; i++) {
		fprintf(fptr, "%d\n", logs[i]);
	}
	fclose(fptr);
	return 0;
}

void show_summary(const int logs[], int add_count) {
	int total_duration=0, highest_duration;

	printf("------- ALL ENTRIES -------\n");	
	// Check if there's no entries added
	if(add_count <= 0) {
		printf("You havn't added any entries yet.\n");
		return;
	}
	
	// Print all entries & Generate summary
	highest_duration = logs[0];	
	for(int i=0; i<DAYS_COUNT; i++) {
		// Check if the entry is empty or not
		if(logs[i] == -1) {
			printf("%s: _____\n", DAYS[i]);			
		}
		else {
			printf("%s: %d mins\n", DAYS[i], logs[i]);
			total_duration += logs[i];
			if(logs[i] > highest_duration)
				highest_duration = logs[i];						
		}
	}
	printf("\n");
	
	// Print summary
	printf("------- SUMMARY -------\n");
	printf("Total listening: %d mins\n", total_duration);
	printf("Average listening: %.2f mins\n", (float)total_duration / add_count);
	printf("Highest listening: %d mins\n", highest_duration);	
}

void delete_all_data(int logs[], int *add_count) {
	char response;

	printf("------- DELETE DATA -------\n");
	
	// Check if the file has any entries
	if(*add_count == 0) {
		printf("There's no data to delete.\n");
		return;
	}	
	
	printf("Are you sure about deleting all data?\n");
	printf("(Press 'y' to confirm, any key to cancel) ");
	scanf(" %c", &response); // Add 'space' before %c to avoid getting \n automatically from previous input
	// Checking the confirmation response
	if(tolower(response) != 'y') {
		printf("Delete request cancelled.\n");
		return;
	}
	
	// Remove all data from file
	FILE *fptr = fopen(FILE_NAME, "w");
	if(fptr == NULL) {
		printf("We're having an issue in removing data, Please try again later!\n");
		return;
	}
	
	// Resetting the array & Added entry count
	*add_count = 0;
	for(int i=0; i<DAYS_COUNT; i++) {
		logs[i] = -1;
	}	
	
	fclose(fptr);
	printf("We've removed all your data.\n");
}

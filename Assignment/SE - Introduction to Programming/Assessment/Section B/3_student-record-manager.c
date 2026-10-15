/*
Task 3: Student Record Manager
Build a C program using structures and functions to store, display, and identify the top performer among a group of students.
- Define a struct Student with fields: name (char[50]), rollno (int), marks (float), and grade (char).
- Write a function void assignGrade(struct Student *s) that sets the grade field based on the marks value using the same bands as Task 1.
- In main(), accept data for 3 students, call assignGrade() for each, and display all records in a formatted table with column headers.
- Write a separate function void printTopper(struct Student[], int n) that prints the name and marks of the student with the highest marks.
*/
#include<stdio.h>
#include<string.h>

#define NAME_LENGTH 50
#define STUDENTS_COUNT 3

struct Student {
	char name[NAME_LENGTH];
	int rollno;
	float marks;
	char grade;
};

void removeTrailingNewline(char []);
int getValidInput(const char [], int, int);
float getValidMarks(const char []);

void getStudentData(struct Student *);
void assignGrade(struct Student *);
void show_data(const struct Student [], int);
void printTopper(const struct Student [], int);

int main() {
	struct Student s[STUDENTS_COUNT];
	
	// Input students data
	printf("====== STUDENT RECORD MANAGER ======\n");
	for(int i=0; i<STUDENTS_COUNT; i++) {
		printf("Enter Student-%d data\n", i+1);
		printf("---------------------\n");
		getStudentData(&s[i]);
	}
	// Show students data
	show_data(s, STUDENTS_COUNT);
	// Show topper data
	printTopper(s, STUDENTS_COUNT);

	return 0;
}


void removeTrailingNewline(char str[]) {
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

float getValidMarks(const char prompt[]) {
	float input;
	int return_value;

	do {
		printf("%s", prompt);
		return_value = scanf("%f", &input);
		// Clear input buffer to avoid infinite loop
		int ch;
		while((ch = getchar()) != '\n' && ch != EOF);

		if(return_value != 1) {
			// If input is non-numeric
			printf("Invalid input, Try again!\n");
		} 
		else if(input<0 || input>100) {
			// If marks are outside the range 0 to 100
			printf("Invalid input, Enter a number between 0 and 100.\n");
		}
		else {
			// Return valid input
			return input;
		}
	} while(1);	
}

void assignGrade(struct Student *s) {
	float marks = s->marks;
	
	if(marks >= 90) {
		s->grade = 'A';
	}
	else if(marks >= 75) {
		s->grade = 'B';
	}
	else if(marks >= 60) {
		s->grade = 'C';		
	}
	else if(marks >= 45) {
		s->grade = 'D';
	}
	else {
		s->grade = 'F';
	}
}

void getStudentData(struct Student *s) {
	// Input name
	printf("Name: ");
	fgets(s->name, NAME_LENGTH, stdin); // Input string with space allowed
	removeTrailingNewline(s->name); // Remove newline char caught by "fgets()"
	// Input roll no.
	s->rollno = getValidInput("Roll No: ", 1, 100);
	// Input marks
	s->marks = getValidMarks("Marks: ");
	// Call for assigining grade
	assignGrade(s);
	printf("\n");
}

void show_data(const struct Student s[], int len) {
	printf("====== STUDENTS DATA ======\n");
	printf("%-25s %-12s %-10s %-10s\n","Name", "Roll No", "Marks", "Grade");
    printf("-----------------------------------------------------------\n");

	for(int i=0; i<len; i++) {
		printf("%-25s %-12d %-10.2f %-10c\n", s[i].name, s[i].rollno, s[i].marks, s[i].grade);	
	}
	printf("\n");
}

void printTopper(const struct Student s[], int n) {
	// Find the topper student
	int topper_student_index = 0;
	
	for(int i=1; i<n; i++) {
		if(s[i].marks > s[topper_student_index].marks) {
			topper_student_index = i;
		}
	}
	
	// Print topper student data
	printf("====== TOPPER DETAILS ======\n");
	printf("Name: %s\n", s[topper_student_index].name);
	printf("Roll No: %d\n", s[topper_student_index].rollno);
	printf("Marks: %.2f\n", s[topper_student_index].marks);
	printf("Grade: %c\n", s[topper_student_index].grade);
	printf("\n");
}


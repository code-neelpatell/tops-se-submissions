/*
1. Create a Task class in your favorite OOP language (Java, Python, or C++) with properties: title and isDone. 
Add a method markDone() that sets isDone to true, and a method display() that prints the task with its status.
2. Build a simple TaskList class/object that stores multiple Task objects and provides addTask(title), markTaskDone(index), 
and showTasks() methods. Demonstrate adding 3 tasks, marking one as done, and displaying all tasks with their statuses.
*/
#include<iostream>
#include<limits>
#include<string>
using namespace std;

class Task {
	public:
		static const int TASK_LENGTH = 100;
	private:
		string title;
		bool isDone;
		
	public:
		Task() : title(""), isDone(false) { }

		Task(string title, bool status) : title(title), isDone(status) { }
		
		void setTitle(string title) {
			this->title = title;
		}
		
		void markDone() {
			isDone = true;
		}
		
		void display() {
			cout << title << " - " << (isDone ? "DONE" : "NOT DONE") << "\n";
		}
};

class TaskList {
	public:
		static const int TASKS_LIMIT = 5;
	private:
		Task tasks[TASKS_LIMIT];
		int taskCount;
		
	public:
		TaskList() : taskCount(0) {	}
		
		void addTask(string title) {
			if(taskCount < TASKS_LIMIT) {
				tasks[taskCount].setTitle(title);
				taskCount++;
			} 
			else {
				cout << "Task list is full!\n";
			}
		}
		
		void markTaskDone(int index) {
			if(index >= 0 && index < taskCount) {
				tasks[index].markDone();			
			}
			else {
				cout << "Invalid task index!\n";
			}
		}
		
		void showTasks() {
			cout << "Task List:\n";
			for(int i=0; i<TASKS_LIMIT; i++) {
				if(i>=taskCount) {
					cout << "(" << i+1 << ") [Empty]\n";
				}
				else {
					cout << "(" << i+1 << ") ";
					tasks[i].display();					
				}
			}
			cout << "\n";
		}
};

int getValidInput(string, int, int);

int main() {
	TaskList tl;
	int taskCount = 0;
	string taskTitle;
	
	// Add tasks
	printf("Create task list:\n");
	for(int i=0; i<3; i++) {
		printf("Enter task %d: ", i+1);
		getline(cin, taskTitle);
		tl.addTask(taskTitle);
		taskCount++;
	}
	printf("\n");
	
	// Print all tasks
	tl.showTasks();
	
	// Select task to mark as complete	
	int selectedTaskIndex = getValidInput("Select task to mark as complete: ", 1, taskCount) - 1;
	tl.markTaskDone(selectedTaskIndex);

	// Print all updated tasks
	tl.showTasks();
	
	return 0;
}

int getValidInput(string prompt, int min, int max) {
	int input;

	while(true) {
		cout << prompt;
		
		if(!(cin >> input)) {
			cout << "Invalid input. Please enter an integer.\n";
			// Clears input error state
			cin.clear();
			// Clears input buffer
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			continue;
		}
		
		// Reject extra characters after the integer
		char extra;
		if (cin.get(extra) && extra != '\n') {
            cout << "Invalid input. Enter a single integer.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

		if (input < min || input > max) {
            cout << "Invalid input. Enter a number between "
                 << min << " and " << max << ".\n";
            continue;
        }

        return input;
 	}
}



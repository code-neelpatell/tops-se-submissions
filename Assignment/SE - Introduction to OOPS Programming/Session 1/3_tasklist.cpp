/*
Create a Task class in your favorite OOP language (Java, Python, or C++) with properties: title and isDone. 
Add a method markDone() that sets isDone to true, and a method display() that prints the task with its status.
*/
#include<iostream>
#include<string>
using namespace std;

class Task {
	private:
		string title;
		bool isDone;
		
	public:
		Task(string title, bool status) : title(title), isDone(status) { }
		
		void markDone() {
			isDone = true;
		}
		
		void display() {
			cout << title << " - " << (isDone ? "DONE" : "NOT DONE") << "\n";
		}
};

int main() {
	Task t1("Complete class assignment", false);
	t1.display();

	t1.markDone();
	t1.display();
	
	return 0;
}

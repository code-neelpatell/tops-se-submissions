/*
Given a file called insta_followers.txt containing Instagram usernames (one per line), write a program to count and display 
the total number of followers listed in the file. Constraint: Do not use any array or vector to store the names—just count as you read.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int usersCount = 0;
	// Open file for reading
	ifstream readFile("insta_followers.txt");
	string line;
	
	// Check if file opened successfully
	if(!readFile.is_open()) {
		cout << "Error in opening file for reading.\n";
		return 1;
	}
	
	while(getline(readFile, line)) {
		usersCount++;
	}
	
	// Close file
	readFile.close();
	
	// Print total count
	cout << "Total Instagram followers listed: " << usersCount << "\n";
	return 0;
}

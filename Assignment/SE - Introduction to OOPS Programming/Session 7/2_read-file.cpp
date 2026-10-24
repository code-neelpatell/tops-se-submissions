// Read all song names from my_fav_songs.txt using ifstream and display each song on a new line in the console.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	// Open file for reading
	ifstream file("my_fav_songs.txt");
	string line;
	
	// Check if file opened successfully
	if(!file.is_open()) {
		cout << "Error opening file for reading.\n";
		return 1;
	}
	
	// Reading file data till end of file
	cout << "Reading songs from file:\n";
	int count = 0;
	while(getline(file, line)) {
		count++;
		cout << count << ") " << line << "\n";
	}
	
	// Close file
	file.close();
	
	return 0;
}

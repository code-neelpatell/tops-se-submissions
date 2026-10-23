/*
Modify your Playlist class so that it auto-saves the playlist name to a file called autosave.txt when the object is destroyed, 
simulating an auto-save feature like Spotify. Hint: Write the file-saving code inside the destructor.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Playlist {
	string name;
	
	public:
		// Constructor
		Playlist() : name("My Favourites") {
			cout << "Welcome to '" << name << "' Playlist.\n";
		}
		
		// Destructor
		~Playlist() {
			// Saving playlist name in file
			
			// Open File
			ofstream myFile("autosave.txt");
			
			// Check if file opened successfully
			if(!myFile.is_open()) { 
				cout << "Could not open the file for writing!\n";
				return;		
			}
			
			// Write in file
			myFile << name;
			// Close file
			myFile.close();
			
			cout << "Playlist name saved in file.\n";
		}
		
};

int main() {
	Playlist pl;
	return 0;
}

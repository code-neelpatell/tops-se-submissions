// Modify your code to append a new song name entered by the user to my_fav_songs.txt without overwriting the existing list.
// Hint: Open the file in append mode using ofstream.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Playlist {
	string songs[5];
	int count;
	
	public:
		Playlist() : count(0) {	}
		
		void addSong(string songTitle) {
			// Check if paramer is empty string
			if(songTitle.empty()) {
				cout << "Song title can't be empty.\n";
				return;
			}
			
			// Check exceeding limit
			if(count >= 5) {
				cout << "Storage limit exceeded, You can't add more songs.\n";
				return;
			}
			
			// Add song in array
			songs[count] = songTitle;
			count++;
			cout << "Song added in the playlist.\n";
		}
		
		void appendFile() {
			// Open file for appending
			ofstream file("my_fav_songs.txt", ios::app);
			
			// Check if file opened successfully
			if(!file.is_open()) {
				cout << "Error opening file for writing.\n";
				return;
			}
			
			// Appending song name in file
			for(int i=0; i<count; i++) {
				file << songs[i] << "\n";
			}
			
			//close file
			file.close();
			cout << "New song name added in file.\n";
		}
};

int main() {
	Playlist playlist;
	
	string songTitle;
	cout << "Enter a song name you want to add in file: ";
	cin >> songTitle;
	cout << "\n";
	
	
	playlist.addSong(songTitle);
	cout << "\n";
	
	playlist.appendFile();
	
	return 0;
}

// Create a text file called my_fav_songs.txt and write the names of your 5 favorite songs into it using ofstream.
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
		
		void writeFile() {
			// Open file for writing
			ofstream file("my_fav_songs.txt");
			
			// Check if file opened successfully
			if(!file.is_open()) {
				cout << "Error opening file for writing.\n";
				return;
			}
			
			// Writing song name in file
			for(int i=0; i<count; i++) {
				file << songs[i] << "\n";
			}
			
			//close file
			file.close();
			cout << "All song names written in file.\n";
		}
};

int main() {
	Playlist playlist;
	
	playlist.addSong("Chaleya");
	playlist.addSong("Nanchaku");
	playlist.addSong("Blinding Lights");
	playlist.addSong("Jungli Kutta");
	playlist.addSong("Heeriye");
	cout << "\n";
	
	playlist.writeFile();
	
	return 0;
}

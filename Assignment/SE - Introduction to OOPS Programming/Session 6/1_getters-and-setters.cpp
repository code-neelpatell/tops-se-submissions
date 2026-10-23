/*
Create a class called Song in your preferred OOP language with private properties title and artist. 
Add public getter and setter methods to access and modify these properties, then create an object and update its title.
*/
#include <iostream>
#include <string>
using namespace std;

class Song {
	string title;
	string artist;
	
	public:
		Song(string title, string artist) : title(title), artist(artist) { }
		
		// Getters
		string getTitle() const { return title; }
		
		string getArtist() const { return artist;	}
		
		// Setters
		void setTitle(string newTitle) {
			if(newTitle.empty()) {
				cout << "Title can't be empty!\n";
				return;
			}
			
			title = newTitle;
			cout << "Song's title updated to '" << title << "'.\n";
		}	 

		void setArtist(string newArtist) {
			if(newArtist.empty()) {
				cout << "Artist name can't be empty!\n";
				return;
			}
			
			artist = newArtist;
			cout << "Song's artist updated to '" << artist << "'.\n";
		}	 
};

int main() {
	Song song1("Desi Kalakaar", "Yo Yo Honey Singh");
	
	// Using getters to get class data
	cout << "Song: " << song1.getTitle() << " by " << song1.getArtist() << ".\n";
	cout << "\n";
	
	// Using setters to modify class data
	song1.setTitle("Barsaat");
	song1.setArtist("Banjare");
	cout << "\n";

	// Print updated data
	cout << "Song: " << song1.getTitle() << " by " << song1.getArtist() << ".\n";
	
	return 0;
}

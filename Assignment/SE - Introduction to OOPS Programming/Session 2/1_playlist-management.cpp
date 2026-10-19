/*
1. Create a class called Playlist with properties: name (string), createdOn (date), and isPublic (boolean). Instantiate an object 
of Playlist and print all its properties.
2. Add a member function to your Playlist class named togglePublic() that switches isPublic between true and false each time it is called. 
Demonstrate by toggling the value twice and printing the result each time.
3. Extend your Playlist class to include a member function addSong(songTitle) that adds the song title to an array property called songs. 
Demonstrate by adding three song titles and displaying the updated songs list. Hint: Initialize songs as an empty array inside the constructor.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

// Function to get the current year
int getCurrentYear() {
    time_t now = time(NULL);
    struct tm* dateInfo = localtime(&now);
    return dateInfo->tm_year + 1900;
}

class Date {
	private:
		int year;
		int month;
		int day;
	public:
		static const int CURRENT_YEAR;
				
		bool setDate(int day, int month, int year) {
			if(year>0 && year<=CURRENT_YEAR && month >=1 && month<=12 && day>=1 && day<=31) {
				this->year = year;
				this->month = month;
				this->day = day;
				return true;
			}
			else {
				return false;
			}
		}
		
		void showDate() const {
			cout << day << "-" << month << "-" << year;
		}
};
// Initialize the static constant
const int Date::CURRENT_YEAR = getCurrentYear();

class Playlist {
	private:
		static const int SONGS_LIMIT = 10;
		string name;
		Date createdOn;
		string songs[SONGS_LIMIT];
		int songsCount;
		bool isPublic;	
		bool isValid;
	public:
		Playlist(string name, string createdDate, bool isPublic) : isValid(false), songsCount(0), isPublic(false), songs{} {
			// Converts string into stream so we can fetch data from it like input
			istringstream stm(createdDate);		

		    int day, month, year;
			char delim;

		    // Fethcing the int data
		    // check if the date string is malformed
			if (!(stm >> day >> delim >> month >> delim >> year)) {
			    isValid = false;
			    cout << "Invalid date format!\n";
				cout << "\n";
			    return;
			}

		    // Setting the date
		    isValid = createdOn.setDate(day, month, year);

		    // Showing error for invalid date
		    if(!isValid) {
			    cout << "Invalid date!\n";
				cout << "\n";
		    	return;
		    }
		    
		    // Assigning the other data
		    this->name = name;
		    this->isPublic = isPublic;
		}
		
		void addSong(string songTitle) {
			// Check if we can add more song in list
			if(songsCount >= SONGS_LIMIT) {
				cout << "The playlist's songs limit is full!\n";
				cout << "\n";
				return;
			}
			
			// Verify the song title is valid
			if(songTitle == "" || songTitle == " ") {
				cout << "Invalid song title!\n";
				cout << "\n";
				return;
			}
			
			songs[songsCount] = songTitle;
			songsCount++;

			cout << "New song added in the playlist.\n";
			cout << "\n";
		}
		
		void displaySongs() {
			cout << "Playlist songs:\n";
			cout << "------------------\n";
			for(int i=0; i<songsCount; i++) {
				cout << songs[i] << "\n";
			}			
			cout << "\n";
		}
		
		void showDetails() {
			if(!isValid) {
				cout << "Please assign the object's values first.\n";
				cout << "\n";
				return;
			}
			cout << "Playlist Details:\n";
			cout << "-----------------\n";
			cout << "Name: " << name << "\n";
			cout << "Created Date: "; createdOn.showDate(); cout << "\n";
			cout << "Visibility: " << (isPublic ? "Public" : "Private") << "\n";
			cout << "\n";
		}
		
		void togglePublic() {
			isPublic = !isPublic;
			cout << "Toggled Playlist visibility.\n";
			cout << "\n";
		}
};

int main() {
	// Task 1
	Playlist pl("Chill Vibes", "12-04-2004", true);
	pl.showDetails();
				
	// Task 2
	pl.togglePublic();
	pl.showDetails();
	
	pl.togglePublic();
	pl.showDetails();
	
	// Task 3
	pl.addSong("Shape of You - By Ed Sheeran");
	pl.addSong("Brown Munde - By AP Dhillon");
	pl.addSong("Apna Time Aayega - By Ranveer Singh, DIVINE");
	pl.displaySongs();

	return 0;
}

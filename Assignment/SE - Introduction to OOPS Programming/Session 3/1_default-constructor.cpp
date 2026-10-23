/*
Create a class called Playlist with a default constructor that sets the playlist name to 'My Favourites' and 
prints a welcome message when an object is created.
*/
#include <iostream>
#include <string>
using namespace std;

class Playlist {
	string name;
	
	public:
		// Default constructor
		Playlist() : name("My Favourites") {
			cout << "Welcome to '" << name << "' Playlist.\n";
		}
};

int main() {
	Playlist pl;
	return 0;
}

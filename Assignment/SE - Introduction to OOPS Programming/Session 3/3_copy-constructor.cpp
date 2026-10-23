/*
Create a class Movie with a parameterized constructor and then use a copy constructor to duplicate a Movie object. 
Print both the original and copied movie details to show they are identical.
*/
#include <iostream>
#include <string>
using namespace std;

class Movie {
	string name;
	string director;
	float rating;
	int releaseYear;
	int duration;
	string genre;
	
	public:
		Movie(string name, string director, float rating, int releaseYear, int duration, string genre) : name(name), director(director),
		rating(rating), releaseYear(releaseYear), duration(duration), genre(genre) { }
		
		// Copy constructor
		Movie(const Movie &obj) : name(obj.name), director(obj.director), rating(obj.rating), releaseYear(obj.releaseYear), duration(obj.duration), 
		genre(obj.genre) { }
		
		void showInfo() {
			cout << "---- Movie Details ----\n";
			cout << "Name: " << name << "\n";
			cout << "Director: " << director << "\n";
			cout << "Rating: " << rating << "\n";
			cout << "Release Year: " << releaseYear << "\n";
			cout << "Duration: " << duration << " mins\n";
			cout << "Genre: " << genre << "\n";
			cout << "\n";
		}
};

int main() {
	Movie m1("Dhurandhar", "Aditya Dhar", 8.2, 2025, 214, "Action Thriller");
	m1.showInfo();
	
	Movie m2(m1);
	m2.showInfo();
	
	return 0;
}

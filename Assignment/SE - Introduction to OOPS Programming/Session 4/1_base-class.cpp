/*
Create a base class called SocialMediaUser with properties username and followers, and a method displayProfile() 
that prints the username and follower count.
*/
#include <iostream>
#include <string>
using namespace std;

class SocialMediaUser {
	string username;
	int followers;
	
	public:
		SocialMediaUser(string username, int followers) : username(username), followers(followers) { }
	
		void displayProfile() {
			cout << "---- User Profile ----\n";
			cout << "Username: @" << username << "\n";
			cout << "Followers: " << followers << "\n";
		} 
};

int main() {
	SocialMediaUser u1("neelpatel01", 879);
	u1.displayProfile();
	
	return 0;
}

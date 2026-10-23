/*
1. Create a base class called SocialMediaUser with properties username and followers, and a method displayProfile() 
that prints the username and follower count.

2. Create a Podcaster class that also inherits from SocialMediaUser and adds a property podcastName and a method 
publishEpisode(episodeTitle) that prints 'Episode [episodeTitle] published on [podcastName]'.
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
			cout << "\n";
		} 
};

class Podcaster: public SocialMediaUser {
	string podcastName;
	
	public:
		Podcaster(string username, int followers, string podcastName) : SocialMediaUser(username, followers), podcastName(podcastName) { }
		
		void publishEpisode(string episodeTitle){
			cout << "Episode '" << episodeTitle << "' published on " << podcastName << ".\n";
			cout << "\n";
		}
};

int main() {
	Podcaster u1("neelpatel01", 879, "Neel Patel Show");
	// Inherited method
	u1.displayProfile();
	u1.publishEpisode("Awareness and Spitiruality");
	
	return 0;
}

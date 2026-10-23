/*
1. Create a base class called SocialMediaUser with properties username and followers, and a method displayProfile() 
that prints the username and follower count.

2. Build a YouTuber class that inherits from SocialMediaUser and adds a property channelName and a method uploadVideo(title) 
that prints 'Video [title] uploaded to [channelName]'.
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

class YouTuber: public SocialMediaUser {
	string channelName;
	
	public:
		YouTuber(string username, int followers, string channelName) : SocialMediaUser(username, followers), channelName(channelName) {	}
		
		void uploadVideo(string title) {
			cout << "Video '" << title <<"' uploaded to " << channelName << ".\n";
			cout << "\n";
		}
};

int main() {
	YouTuber u1("neelpatel01", 879, "Neel Patel");
	// Inherited method
	u1.displayProfile();
	u1.uploadVideo("How to become a good programmer");
		
	return 0;
}

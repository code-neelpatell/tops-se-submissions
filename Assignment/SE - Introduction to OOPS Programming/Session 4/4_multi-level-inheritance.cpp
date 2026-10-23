/*
1. Create a base class called SocialMediaUser with properties username and followers, and a method displayProfile() 
that prints the username and follower count.

2. Build a YouTuber class that inherits from SocialMediaUser and adds a property channelName and a method uploadVideo(title) 
that prints 'Video [title] uploaded to [channelName]'.

3. Demonstrate multilevel inheritance by creating a class GamingYouTuber that inherits from YouTuber and adds a method 
streamGame(gameName) which prints '[username] is now streaming [gameName] on [channelName]'.
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
		
		string getUsername() {
			return username;
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
		
		string getChannelName() {
			return channelName;
		}
};

class GamingYouTuber: public YouTuber {
	public:
		GamingYouTuber(string username, int followers, string channelName) : YouTuber(username, followers, channelName) { }
		
		void streamGame(string gameName) {
			cout << "@" << getUsername() << " is now streaming " << gameName << " on " << getChannelName() << ".\n";
			cout << "\n";
		}
};

int main() {
	GamingYouTuber u1("neelpatel01", 879, "Neel Patel");
	// Inherited method  - from super base class
	u1.displayProfile();
	// Inherited method - from base class
	u1.uploadVideo("My new gaming setup");
	u1.streamGame("PUBG");
		
	return 0;
}

/*
1. Create a base class called SocialMediaUser with properties username and followers, and a method displayProfile() 
that prints the username and follower count.

2.1 Build a YouTuber class that inherits from SocialMediaUser and adds a property channelName and a method uploadVideo(title) 
that prints 'Video [title] uploaded to [channelName]'.

2.2 Create a Podcaster class that also inherits from SocialMediaUser and adds a property podcastName and a method 
publishEpisode(episodeTitle) that prints 'Episode [episodeTitle] published on [podcastName]'.

3. Implement hierarchical inheritance by creating an InstagramInfluencer class that inherits from SocialMediaUser and adds a method
postStory(storyTitle) which prints '[username] posted a new story: [storyTitle]'. 
Hint: Think about how SocialMediaUser is the parent for YouTuber, Podcaster, and InstagramInfluencer.
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

class InstagramInfluencer: public SocialMediaUser {
	public:
		InstagramInfluencer(string username, int followers) : SocialMediaUser(username, followers) { }
		
		void postStory(string storyTitle) {
			cout << "@" << getUsername() << " posted a new story: " << storyTitle << ".\n";
			cout << "\n";
		}
};

int main() {
	YouTuber u1("neelpatel01", 879, "Neel Patel");
	// Inherited method
	u1.displayProfile();
	u1.uploadVideo("How to become a good programmer");
		
	Podcaster u2("neelpatel01", 879, "Neel Patel Show");
	// Inherited method
	u2.displayProfile();
	u2.publishEpisode("Awareness and Spitiruality");
	
	InstagramInfluencer u3("neelpatel01", 1056);
	// Inherited method
	u3.displayProfile();
	u3.postStory("Sunday vibes!");

	return 0;
}

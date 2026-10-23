/*
Build a class called InstaStory with a protected property storyViews. 
Create a subclass called SponsoredStory that can access and display the storyViews value.
*/
#include <iostream>
#include <string>
using namespace std;

class InstaStory {
	protected:
		int storyViews;
};

class SponsoredStory: public InstaStory {
	public:
		SponsoredStory(int views) {
			// Modifying the parent class's member
			storyViews = views;
		} 
		
		void showViews() {
			// Accesing the member from parent class
			cout << "The story has got " << storyViews << " views.\n";
		}
};

int main() {
	SponsoredStory story(2300);
	story.showViews();
	
	return 0;
}

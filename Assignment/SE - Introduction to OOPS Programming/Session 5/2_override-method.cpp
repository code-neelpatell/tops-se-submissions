/*
Build two classes, InstagramUploader and YouTubeUploader, each with a method uploadContent(). Both should extend a base class 
SocialMediaUploader and override uploadContent() to print a message showing how uploading works differently for Instagram and YouTube.
*/
#include <iostream>
#include <string>
using namespace std;

class SocialMediaUploader {
	public:
		virtual void uploadContent() {
			cout << "Uploaded content on Social Media.\n";
		}
};

class InstagramUploader: public SocialMediaUploader {
	public:
		void uploadContent() override {
			cout << "Uploaded content on Instagram.\n";
		}
};

class YouTubeUploader: public SocialMediaUploader {
	public:
		void uploadContent() override {
			cout << "Uploaded content on YouTube.\n";
		}
};


int main() {
	InstagramUploader iu;
	YouTubeUploader yu;
	
	iu.uploadContent();
	yu.uploadContent();

	return 0;
}

// Build a structure called InstaProfile with fields: username (string), followers (integer), and a nested structure Bio with fields: description (string) and age (integer). 
// Initialize an InstaProfile variable with your own details and display all fields.
#include<stdio.h>

struct InstaBio {
	char description[200];
	int age;
};

struct InstaProfile {
	char username[15];
	int followers;
	struct InstaBio bio;
};

int main() {
	struct InstaProfile profile = { "neelpatel_1256", 768, { "Music & travel enthusiast", 25 } };
	
	printf("==== INSTAGRAM PROFILE ====\n");
	printf("Username: @%s\n", profile.username);
	printf("Followers: %d\n", profile.followers);
	printf("Description: %s\n", profile.bio.description);
	printf("Age: %d\n", profile.bio.age);
	
	return 0;
}

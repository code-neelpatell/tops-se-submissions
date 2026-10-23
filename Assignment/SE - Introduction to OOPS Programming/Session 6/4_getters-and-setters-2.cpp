/*
Refactor the following code so that the user’s phone number in the UserProfile class is private and can only be set or retrieved 
using public methods. Hint: Add private access modifier to the phone number and create setPhoneNumber() and getPhoneNumber() methods.
*/
#include <iostream>
#include <string>
using namespace std;

class UserProfile {
	string phoneNumber;
	
	public:
		UserProfile(string phoneNumber) : phoneNumber(phoneNumber) { }
				
		// Getter
		string getPhoneNumber() { return phoneNumber; }
		
		// Setter
		void setPhoneNumber(string newPhoneNumber) { 
			if(newPhoneNumber.empty()) {
				cout << "Phone number can't be empty.\n";
				return;
			}
			
			phoneNumber = newPhoneNumber;
			cout << "Your Phone number is updated now.\n";
		}
};

int main() {
	UserProfile user("8989000000");
	
	// Getting phone number value by getter
	cout << "Phone number: " << user.getPhoneNumber() << "\n";
	cout << "\n";
	
	// Modifying phone number by setter
	user.setPhoneNumber("8989555555");
	cout << "\n";
	
	// Getting updated phone number value by getter
	cout << "Phone number: " << user.getPhoneNumber() << "\n";
	
	return 0;
}

/* 
1. Create a Content class with properties: title, platform, views, and status. Write a method to display all details of a Content object.

2. Build a console menu that lets users add new content ideas (title, platform, views, status) and save each entry to a text file named content_list.txt. Hint: Use file handling to append each new content item to the file.

3. Implement a function to read all content items from content_list.txt and display them in a numbered list, showing title and platform for each.

4. Add an option in your console app to let users update the status of any content idea by selecting its number from the displayed list and saving the change back to the file. Hint: You will need to read all items, modify the selected one, and overwrite the file.

5. Add a feature to delete a content item by its number from the list, update the file accordingly, and display the updated list to confirm deletion.

Status options: Draft, Scheduled, Puhlished, Archived
*/
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#define FILE_NAME "content_list.txt"

using namespace std;

struct ContentDetails {
    string title;
    string platform;
    int views;
    string status;
};

class Content {
    string title;
    string platform;
    int views;
    string status;
    bool isSaved;

    public:
    Content(ContentDetails details) : isSaved(false) {
        // Check if values are invalid
        if(details.title.empty() || details.platform.empty() || details.views < 0 || details.status.empty()) {
            throw runtime_error("Invalid data for object creation.");
        }

        // Assign values
        title = details.title;
        platform = details.platform;
        views = details.views;
        status = details.status;
    }

    void showDetails() {
        cout << "Title: " << title << "\n";
        cout << "Platform: " << platform << "\n";
        cout << "Views: " << views << "\n";
        cout << "Status: " << status << "\n";
    }

    void saveDetails() {
        // Don't allow writting same data again in file
        if(isSaved) {
            cout << "Details has already saved in file.\n";
            return;
        }

        // Open file in append mode
        ofstream file(FILE_NAME, ios::app);

		// Check if file opened successfully
		if(!file.is_open()) {
            throw runtime_error("Error in opening file to save data.");
        }

        // Write details in file (saperated by ,)
        file << title << "," << platform << "," << views << "," << status << "\n";

        // Check if data has been written successfully
        if(!file) {
            throw runtime_error("Error in saving data in file.");
        }

        // Close file
        file.close();
        isSaved = true;
        cout << "New content idea saved in file.\n";
    }
};

int getIntInput(const string &);
string getStrInput(const string &);
int getMenuSelection();
string getContentStatusInput();
int getContentViewsInput(const string &);
int getContentViewsInput(const string &, const string &, const int);
ContentDetails getContentDetails();
void addContent();
void showAllData();
void loadContentData(map<int, ContentDetails> &);
void writeContentData(const map<int, ContentDetails> &);
void updateContentStatus();
void deleteContent();
void exitProgram(bool &);

int main() {
    bool keepGoing = true;
    int selection;

    while(keepGoing) {
        // Get user selection
        selection = getMenuSelection();
        cout << "\n";

        switch(selection) {
            // Allocate right operation according to selection
            case 1: addContent(); break;
            case 2: showAllData(); break;
            case 3: updateContentStatus(); break;
            case 4: deleteContent(); break;
            case 5: exitProgram(keepGoing); break;
        }
        
        if(keepGoing) cout << "\n";
    }

    return 0;
}

int getIntInput(const string &prompt) {
    int input;
    cout << prompt;

    // Iterate until it gets valid int input
    while(!(cin >> input)) {
        cout << "Invalid input. " << prompt;
        // Resets the error state, to allow it taking input again
        cin.clear();
        // Clears the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Clears the input buffer (in case it has any aside from int data)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

string getStrInput(const string &prompt) {
    string input;
    cout << prompt;
    getline(cin, input);

    // Iterate until it gets valid string input
    while(input.empty()) {
        cout << "Invalid input. " << prompt;
        getline(cin, input);
    }

    return input;
}

string getContentStatusInput() {
    cout << "Status Options:\n";
    cout << "1) Draft\n";
    cout << "2) Scheduled\n";
    cout << "3) Published\n";
    cout << "4) Archived\n";

    // Iterate until it gets valid selection
    while(true) {
        // Get input selection
        int selection = getIntInput("Select: ");
        // Return value according to selection number
        switch(selection) {
            case 1: return "Draft";
            case 2: return "Scheduled";
            case 3: return "Published";
            case 4: return "Archived";  
            default: cout << "Invalid selection. ";      
        }
    }
}

int getValidContentViewsInput() {
    int views;
    // Iterate until it gets valid views count
    while(true) {
        views = getIntInput("Views: ");

        if(views >= 0) {
            return views;
        }
        cout << "Invalid count. ";
    }
}

int getContentViewsInput(const string &status) {
    // If content is already published or archived
    if(status == "Published" || status == "Archived") {
        return getValidContentViewsInput();
    }
    // Otherwise there will be no views currently
    else {
        return 0;
    }
}

int getContentViewsInput(const string &newStatus, const string &currentStatus, const int currentViews) {
    if(currentStatus=="Draft" && newStatus!="Scheduled") {
        return getValidContentViewsInput();
    }
    else if(currentStatus=="Scheduled" && newStatus!="Draft") {
        return getValidContentViewsInput();
    }
    else if(currentStatus=="Published" && newStatus!="Archived") {
        return 0;
    }
    else if(currentStatus=="Archived" && newStatus!="Published") {
        return 0;
    }

    return currentViews;
}

ContentDetails getContentDetails() {
    ContentDetails details;

    cout << "--- ADD NEW CONTENT ---\n";
    // Get title
    details.title = getStrInput("Title: ");
    // Get platform
    details.platform = getStrInput("Platform: ");
    // Get status
    details.status = getContentStatusInput();
    // Get/Assign views
    details.views = getContentViewsInput(details.status);

    return details;
}

int getMenuSelection() {
    cout << "=== CONTENT MANAGEMENT SYSTEM ===\n";
    cout << "1) Add Idea\n";
    cout << "2) View All\n";
    cout << "3) Update Status\n";
    cout << "4) Delete Record\n";
    cout << "5) Exit\n";

    // Iterate until it gets valid selection
    while(true) {
        // Get input selection
        int selection = getIntInput("Select: ");
        if(selection>=1 && selection<=5) {
            return selection;
        }
        cout << "Invalid selection. ";
    }
}

void addContent() {
    try {
        // Create object with user data
        Content c1(getContentDetails());
        cout << "\n";
        
        // Call method to show object details
        cout << "Stored Content details:\n";
        c1.showDetails();
        cout << "\n";
        
        // Call method to save details in file
        c1.saveDetails();
    }
    catch(const runtime_error &e) {
        cout << e.what() << "\n";
    }
}

void showAllData() {
    // Open file in read mode
    ifstream file(FILE_NAME);

	// Check if file opened successfully
	if(!file.is_open()) {
        throw runtime_error("Error in opening file to read data.");
    }

    // Read details from file
    string line, viewsStr;
    int count=0;
    ContentDetails details;
    
    cout << "--- View All Ideas ---\n";
    // Iterate until it can read data
    while(getline(file, line)) {
        // Converts input string into input like stream, to fetch data from it
        stringstream ss(line);

        // Fetch data from string stream (saperated by ,)
        if(getline(ss, details.title, ',') && getline(ss, details.platform, ',') && getline(ss, viewsStr, ',') && getline(ss, details.status, ',')) {
            count++;

            // Converting string into int
            details.views = stoi(viewsStr);

            cout << "Idea " << count << ":\n";
            cout << "Title: " << details.title << "\n";
            cout << "Platform: " << details.platform << "\n";
            cout << "Views: " << details.views << "\n";
            cout << "Status: " << details.status << "\n";
            cout << "\n";
        }
    }    
    
    // Close file
    file.close();

    // Check if no records found
    if(count == 0) {
        cout << "No records to show.\n";
    }
}

void loadContentData(map<int, ContentDetails> &contentData) {
    // Open file in read mode
    ifstream file(FILE_NAME);

	// Check if file opened successfully
	if(!file.is_open()) {
        throw runtime_error("Error in opening file to read data.");
    }

    // Read details from file
    string line, viewsStr;
    int count=0;
    ContentDetails details;
    
    // Iterate until it can read data
    while(getline(file, line)) {
        // Converts input string into input like stream, to fetch data from it
        stringstream ss(line);

        // Fetch data from string stream (saperated by ,)
        if(getline(ss, details.title, ',') && getline(ss, details.platform, ',') && getline(ss, viewsStr, ',') && getline(ss, details.status, ',')) {
            count++;
            // Convert string data into int
            details.views = stoi(viewsStr);
            // Insert data in array
            contentData[count] = {details.title, details.platform, details.views, details.status};
        }
    }    
    
    // Close file
    file.close();
}

void writeContentData(const map<int, ContentDetails> &contentData) {
    // Open file in write mode
    ofstream file(FILE_NAME);

	// Check if file opened successfully
	if(!file.is_open()) {
        throw runtime_error("Error in opening file to save data.");
    }

    // Iterate for all elements in array
    for(const auto &content: contentData) {
        // Write details in file (saperated by ,)
        file << content.second.title << "," << content.second.platform << "," << content.second.views << "," << content.second.status << "\n";
    
        // Check if data has been written successfully
        if(!file) {
            throw runtime_error("Error in saving data in file.");
        }
    }

    // Close file
    file.close();    
}

void updateContentStatus() {
    // Display all data from file
    showAllData();

    try {
        // Load all data in array
        map<int, ContentDetails> contentData;
        loadContentData(contentData);

        // Check if there's no data
        if(contentData.empty()) {
            return;
        }

        cout << "--- Update Record Status ----\n";
        // Get record no
        int ideaNo = getIntInput("Enter Idea No: ");

        // Check if selection no is valid
        if(ideaNo <=0 || ideaNo > contentData.size()) {
            cout << "Invalid selection. Try again later.\n";
            return;
        }    

        // Get updated status
        string updatedStatus = getContentStatusInput();
        // Fetch current data
        string currentStatus = contentData[ideaNo].status;
        int currentViews = contentData[ideaNo].views;

        // Check if new and current status is same
        if(updatedStatus == currentStatus) {
            cout << "No changes detected.\n";
            return;
        }

        // Updated views (if needed)
        int updatedViews = getContentViewsInput(updatedStatus, currentStatus, currentViews);

        // Update data of selected idea
        contentData[ideaNo].status = updatedStatus;
        contentData[ideaNo].views = updatedViews;

        // Overwrite the file with updated data
        writeContentData(contentData);

        cout << "Data has been updated and saved in file.\n";
    }
    catch(const runtime_error &e) {
        cout << e.what() << "\n";
    }
}

void deleteContent() {
    // Display all data from file
    showAllData();

    try {
        // Load all data in array
        map<int, ContentDetails> contentData;
        loadContentData(contentData);

        // Check if there's no data
        if(contentData.empty()) {
            return;
        }

        cout << "--- Delete Record ----\n";
        // Get record no
        int ideaNo = getIntInput("Enter Idea No: ");

        // Check if selection no is valid
        if(ideaNo <=0 || ideaNo > contentData.size()) {
            cout << "Invalid selection. Try again later.\n";
            return;
        }    

        // Find the record from array
        auto it = contentData.find(ideaNo);
        // Check if we found record
        if(it == contentData.end()) {
            cout << "No record found with given ID.\n";
            return;
        }
        // Remove the selected value
        contentData.erase(it);
        
        map<int, ContentDetails> updatedData;
        int newId = 1;
        // Reshift the elemens to cover the empty index
        for(const auto &content: contentData) {
            updatedData[newId++] = content.second;
        }
        // Update thecontent data with updated data
        contentData = move(updatedData);

        // Overwrite the file with updated data
        writeContentData(contentData);

        cout << "Record has been deleted from file.\n";
    }
    catch(const runtime_error &e) {
        cout << e.what() << "\n";
    }
}

void exitProgram(bool &keepGoing) {
    cout << "Thank you.\n";
    keepGoing = false;
}
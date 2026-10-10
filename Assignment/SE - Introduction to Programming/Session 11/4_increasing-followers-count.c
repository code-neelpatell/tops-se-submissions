// Create a function incrementFollowers(int *followers, int n) that increases each follower count in an array 
// (representing Instagram followers for 5 friends) by 100 using pointer arithmetic, then print the updated counts.
#include<stdio.h>

void incrementFollowers(int *followers, int n) {
	for(int i=0; i<n; i++) {
		*followers += 100; // Increase followers by 100
		followers++; // Shift the pointer to next index
	}
}

int main() {
	int followers[] = {200, 450, 720, 1189, 769};
	int arr_len = sizeof(followers) / sizeof(followers[0]);
	int *followers_ptr = followers;
	
	printf("Before followers increment:\n");
	for(int i=0; i<arr_len; i++) {
		printf("Friend %d: %d\n", i+1, followers[i]);
	}
	printf("\n");
	
	incrementFollowers(followers_ptr, arr_len);
	
	printf("After followers increment:\n");
	for(int i=0; i<arr_len; i++) {
		printf("Friend %d: %d\n", i+1, followers[i]);
	}

	return 0;
}

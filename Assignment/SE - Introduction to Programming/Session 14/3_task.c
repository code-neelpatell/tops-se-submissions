/*
Write a function formatFollowersCount(count) that takes a number and returns a formatted string like Instagram: 
1500 as '1.5K', 1200000 as '1.2M', and numbers below 1000 as-is. Add clear comments and use proper indentation.
*/

#include <stdio.h>

void formatFollowersCount(double count, char formattedStr[]) {
    if (count >= 0 && count < 1000) {
        snprintf(formattedStr, sizeof(formattedStr), "%.0f", count);
    }
    else if (count < 1000000) {
        snprintf(formattedStr, sizeof(formattedStr), "%.1fK", count / 1000.0);
    }
    else if (count < 1000000000) {
        snprintf(formattedStr, sizeof(formattedStr), "%.1fM", count / 1000000.0);
    }
    else {
        snprintf(formattedStr, sizeof(formattedStr), "%.1fB", count / 1000000000.0);
    }
}

int main() {
	char formattedStr[10];

	formatFollowersCount(850, formattedStr);
    printf("Below 1000: %s\n", formattedStr);

	formatFollowersCount(1500, formattedStr);
    printf("Thousands: %s\n", formattedStr);
    
    formatFollowersCount(1200000, formattedStr);
    printf("Millions: %s\n", formattedStr);
    
    formatFollowersCount(2500000000.0, formattedStr);
    printf("Billions: %s\n", formattedStr);
    
    return 0;
}

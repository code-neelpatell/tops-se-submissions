/*
Build a function formatPrice that takes a price in rupees and returns a string formatted like Flipkart's price tag (e.g., '?1,599'). 
Use this function to display prices for three different products.

Logic:
0. Only enter if number is more then 3 digits or positive
1. reverse the string  
2. for first iteration add comma after 3 dgits
3. After that add comma after 2 elements
4. Remove last added comma
5. Revrse the stored string

i.e. 89000 -> 00098 -> 000,98 -> 89,000
i.e. 12486 -> 68421 -> 684,21 -> 12,486
i.e. 100792 -> 297001 -> 297,00,1 -> 1,00,792
i.e. 1297367 -> 7637921 -> 763,79,21 -> 12,97,367
*/

#include<stdio.h>
#include<string.h>

int find_length(const char []);
void formatPrice(const char [], char []);

int main() {
	int product_price[] = { 89000, 100792, 1297367};
	int product_count = sizeof(product_price) / sizeof(product_price[0]);
	char r_price[20], f_price[40];
		
	for(int i=0; i<product_count; i++) {
		if(product_price[i] < 0)
			printf("Product-%d price is invalid!\n", i+1);
		else if(product_price[i] < 1000)
			printf("Product-%d Price: Rs.%d\n", i+1, product_price[i]);	
		else {
			// Converting price into string
			snprintf(r_price, sizeof(r_price), "%d", product_price[i]);
			formatPrice(r_price, f_price);
			printf("Product-%d Price: Rs.%s\n", i+1, f_price);					
		}			
	}
		
	return 0;
}

int find_length(const char str[]) {
	int count=0;
	while(str[count]!='\0' && str[count]!='\n') count++;
	return count;
}

void formatPrice(const char price[], char f_price[]) {
	int length = find_length(price);
	int i=length-1; 
	int j=0, count=0;
	
	// Adding ',' between digits - In reversed order
	while(1) {
		count++;
		j++;
		if(i < 0) {
			break;
		} else if(count==4 && j==4){
			f_price[count-1] = ',';
			j=0;
		} else if(count>4 && j==3){
			f_price[count-1] = ',';
			j=0;
		} else {
			f_price[count-1] = price[i];
			i--;						
		}
	}
	f_price[count-1] = '\0'; // Add \0 at the last index to indicate end of string
	
	i=0, j=find_length(f_price)-1;
	char temp;
	// Reverse the string
	while(i < j) {
		// i=starting index, j=last index => Swap chars
		temp = f_price[i];
		f_price[i] = f_price[j];
		f_price[j] = temp;
		i++;
		j--;	
	}		
}

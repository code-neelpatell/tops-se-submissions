/*
Write a program that takes a user's age and checks eligibility for three things using if-else statements: 
if age >= 18, print 'Eligible for Driving License'; if age >= 21, also print 'Eligible for Credit Card'; 
if age >= 25, also print 'Eligible for Car Rental'. Print all applicable messages for the given age.
*/

#include<stdio.h>

int main() {
	int age;
	
	printf("Enter your age: ");
	scanf("%d", &age);
	
	if(age > 0){
		if(age >= 18)
			printf("\nEligible for Driving License");
		if(age >= 21)
			printf("\nEligible for Credit Card");
		if(age >= 25)
			printf("\nEligible for Car Rental");
	}
	else
		printf("Please enter a valid age!");
	
	
	return 0;
}

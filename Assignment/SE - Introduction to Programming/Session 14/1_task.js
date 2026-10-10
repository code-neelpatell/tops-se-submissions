/* 
Given the following buggy code meant to calculate the total price of a Zomato order, identify and fix the syntax and runtime errors
Hint: Watch for assignment and loop variable issues.

let items = ["Burger", "Pizza", "Fries"];
let prices = [120, 250, 90];
let total = 0;
for (i = 0; i < items.length; i++) {
    total =+ prices[i]
}
console.log("Total price is: " + total);
*/

let items = ["Burger", "Pizza", "Fries"];
let prices = [120, 250, 90];
let total = 0, i;

for (i = 0; i < items.length; i++) {
    total += prices[i];
}

console.log("Total price is: " + total);

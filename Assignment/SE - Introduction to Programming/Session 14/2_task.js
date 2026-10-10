/*
Rewrite the following code to improve its indentation and add comments explaining each step, 
so that a beginner can understand what it does: function isEven(num){if(num%2==0){return true;}else{return false;}}
*/

// Function to check whether a given number is even or odd
function isEven(num) {
    // Check whether the remainder after division by 2 is zero
    if(num%2==0) {
        // If the remainder is zero, the number is even
        return true;
    } 
    else {
        // Otherwise, the number is odd
        return false;
    }
}
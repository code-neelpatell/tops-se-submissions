/*
You are given a piece of JavaScript code that should print all even numbers from 1 to 10, but it doesn't work as expected:
for (let i = 1; i <= 10; i++) { if (i % 2 = 0) { console.log(i) }}
Find and fix the error, then rewrite the code with good indentation and at least one comment explaining the logic.
*/

for (let i = 1; i <= 10; i++) {
    // Check whether the number is even.
    if (i % 2 === 0) {
        // Print the number if the remainder is zero.
        console.log(i);
    }
}

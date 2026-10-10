// Write a function isEligibleForOffer that takes a user's age and total order value, and returns true if the user is 18 or older 
// AND the order value is above 500, otherwise false. Hint:Use relational and logical operators together.
function isEligibleForOffer(age, orderValue) {
    if(age >= 18 && orderValue > 500) 
        return true;
    return false;
}

console.log(isEligibleForOffer(18, 460));
console.log(isEligibleForOffer(17, 780));
console.log(isEligibleForOffer(18, 520));

// Build a Flipkart-style discount calculator: given product price, discount percentage, and a boolean isMember, 
// use arithmetic and logical operators to calculate the final price (apply an extra 5% off if isMember is true).

function discountCalculator(productPrice, discountPercent, isMember) {
    let discountAmount = productPrice * (discountPercent / 100);
    let finalAmount = productPrice - discountAmount;

    if (isMember) {
        discountAmount = finalAmount * (5 / 100);
        finalAmount = finalAmount - discountAmount;
    }
    return finalAmount;
}

console.log(discountCalculator(3400, 5, false));
console.log(discountCalculator(3400, 5, true));

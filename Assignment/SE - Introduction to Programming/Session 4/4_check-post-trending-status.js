// Given three variables: likes, comments, and shares (all numbers), write code to check if a post is 'trending' on Instagram 
// (at least 1000 likes OR more than 200 comments AND at least 50 shares). Print the result.

function checkPostStatus(likes, comments, shares) {
    if(likes >= 1000 || comments > 200 && shares >= 50)
        return "Post Trending!";
    else
        return "Post not Trending!";
}

console.log(checkPostStatus(998, 50, 54));
console.log(checkPostStatus(784, 204, 50));
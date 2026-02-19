/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let flag = candies.reduce((max, candy) => (candy > max) ? candy : max, 0) - extraCandies;
    return candies.map((candy) => candy >= flag)    
};
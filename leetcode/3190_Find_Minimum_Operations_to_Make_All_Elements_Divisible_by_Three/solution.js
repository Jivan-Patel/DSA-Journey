/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function (nums) {
    return nums.reduce((count, num) => (num % 3 === 0) ? count : count + 1, 0);
};
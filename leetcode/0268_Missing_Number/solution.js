/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let sum = nums.reduce((a, b) => a + b, 0);
    let n = nums.length;

    let nsum = n * (n + 1) / 2;

    return nsum - sum;
};

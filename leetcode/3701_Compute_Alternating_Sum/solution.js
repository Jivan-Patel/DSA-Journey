/**
 * @param {number[]} nums
 * @return {number}
 */
var alternatingSum = function (nums) {
    let result = 0;
    for (let i = 0; i < nums.length; i++)
        result += (i % 2 == 0) ? nums[i] : -nums[i];
    return result;
};
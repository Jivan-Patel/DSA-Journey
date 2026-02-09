/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndices = function (nums) {
    let sum = nums[nums.length - 1];
    let count = 0;
    for (let i = nums.length - 2; i >= 0; i--) {
        let avg = sum / (nums.length - i - 1);
        if (nums[i] > avg) count++;
        sum += nums[i];
    }
    return count;
};
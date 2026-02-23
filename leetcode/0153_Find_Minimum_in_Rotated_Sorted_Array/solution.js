/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    return nums.reduce((min,num) => min > num ? num : min, nums[0]);
};
/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    let maxI = 0;
    for(let i = 0; i < nums.length; i++) {
        if(nums[maxI] < nums[i]) maxI = i;
    }
    return maxI;
};
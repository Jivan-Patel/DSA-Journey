/**
 * @param {number[]} nums
 * @return {number[]}
 */
var numberGame = function (nums) {
    nums.sort((a, b) => a - b);
    let i = 0; 
    while(nums.length > i) {
        let temp = nums[i];
        nums[i] = nums[i + 1];
        nums[i + 1] = temp;
        i = i + 2;
    }
    return nums;
};
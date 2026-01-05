/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let t = nums.length;
    let i = 0;
    for(let j = 0; j < t; j++) {
        if(nums[i] === 0) {
            nums.splice(i,1);
            i--;
            nums.push(0)
        }
        i++;
    }
    return nums;
};
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var transformArray = function (nums) {
    let res = [];
    for (let i = 0; i < nums.length; i++) {
        (nums[i] % 2 == 0) ? res.unshift(0) : res.push(1);
    }
    return res;
};
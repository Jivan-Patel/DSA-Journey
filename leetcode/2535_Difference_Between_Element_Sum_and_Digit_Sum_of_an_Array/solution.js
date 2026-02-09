/**
 * @param {number[]} nums
 * @return {number}
 */
var differenceOfSum = function (nums) {
    let s1 = nums.reduce((sum, num) => sum + num, 0);
    let s2 = nums.join('').split('').reduce((sum, num) => sum + Number(num), 0);
    return Math.abs(s1-s2);
};

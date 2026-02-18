/**
 * @param {number[]} nums
 * @return {number}
 */
var findGCD = function (nums) {
    let min = Infinity
    let max = -Infinity;
    for (let i = 0; i < nums.length; i++) {
        if (min > nums[i]) min = nums[i];
        if (max < nums[i]) max = nums[i];
    }
    let i = min;
    while (i > 0) {
        if (min % i === 0 && max % i === 0) return i;
        i--;
    }
    return 1;
};
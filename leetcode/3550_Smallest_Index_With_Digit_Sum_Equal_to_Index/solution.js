/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestIndex = function (nums) {
    for (let i = 0; i < nums.length; i++) {
        let sum = 0;
        let test = nums[i]
        while (test > 0) {
            sum += (test % 10);
            test = Math.floor(test/10);
        }
        if (sum == i) return i;
    }
    return -1;
};
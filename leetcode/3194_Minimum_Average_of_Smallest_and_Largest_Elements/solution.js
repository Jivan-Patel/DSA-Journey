
/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverage = function (nums) {
    nums.sort((a, b) => a - b);
    let minAvg = Infinity;
    let i = 0;
    let j = nums.length - 1;

    while (j > i) {
        let average = (nums[i] + nums[j]) / 2;
        if (minAvg > average) minAvg = average;
        i++;
        j--;
    }
    return minAvg;
};
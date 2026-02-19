/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRightDifference = function(nums) {
    let sum = 0;
    let leftSum = nums.map(num => {
        sum += num;
        return sum - num;
    });
    let rightSum = nums.map(num => {
        sum -= num;
        return sum;
    })
    for(let i = 0; i < leftSum.length; i++) {
        leftSum[i] = Math.abs(leftSum[i] - rightSum[i]);
    }
    return leftSum;
};
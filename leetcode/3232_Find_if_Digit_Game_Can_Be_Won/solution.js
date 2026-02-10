/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canAliceWin = function(nums) {
    let singleSum = 0;
    let multiSum = 0;
    for(let num of nums) {
        (num < 10) ? singleSum += num : multiSum += num;
    }
    return singleSum !== multiSum;
};
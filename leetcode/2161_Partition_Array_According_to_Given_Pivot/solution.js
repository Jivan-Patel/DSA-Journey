/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]}
 */
var pivotArray = function (nums, pivot) {
    let result = [];
    let countP = 0;
    for (let num of nums) {
        if (num < pivot) result.push(num);
        else if (num == pivot) countP++;
    }
    for (let i = 1; i <= countP; i++) result.push(pivot);
    for (let num of nums)
        if (num > pivot) result.push(num);
    return result;
};
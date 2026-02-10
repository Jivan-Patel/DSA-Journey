/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function (nums) {
    let freq = {};
    let res = [];
    for (let i = 0; i < nums.length; i++) {
        if (freq[nums[i]]) freq[nums[i]]++;
        else freq[nums[i]] = 1;
    }
    for (let key in freq)
        if (freq[key] === 2) res.push(Number(key));
    return res;
};
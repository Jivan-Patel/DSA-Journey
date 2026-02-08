/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
    let freq = {};
    for (let i = 0; i < nums.length; i++) {
        if (freq[nums[i]]) {
            freq[nums[i]]++;
        }
        else {
            freq[nums[i]] = 1;
        }
    }
    let arr = [];
    for (let keys in freq) {
        arr.push([keys, freq[keys]]);
    }
    arr.sort((a, b) => b[1] - a[1]);
    let res = [];
    for(let i = 0; i < k; i++) {
        res.push(Number(arr[i][0]))
    }
    return res;
};
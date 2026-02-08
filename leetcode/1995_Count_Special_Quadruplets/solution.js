/**
 * @param {number[]} nums
 * @return {number}
 */
var countQuadruplets = function (nums) {
    let freq = {};
    let quadruplet = 0;
    for (let i = 0; i < nums.length; i++) {
        if (freq[nums[i]]) freq[nums[i]].push(i);
        else freq[nums[i]] = [i];
    }
    for (let i = 0; i < nums.length - 3; i++) {
        for (let j = i + 1; j < nums.length - 2; j++) {
            for (let k = j + 1; k < nums.length - 1; k++) {
                let sum = nums[i] + nums[j] + nums[k];
                if (freq[sum]) {
                    for(let index of freq[sum]) {
                        if (index > k) quadruplet++;
                    }
                }
            }
        }
    }
    return quadruplet;
};
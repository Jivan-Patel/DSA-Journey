/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfUnique = function (nums) {
    let freq = {};
    for (let num of nums) {
        if (freq[num] !== undefined) freq[num] = false;
        else freq[num] = true;
    }
    return Object.keys(freq).reduce((count, num) => {
        return (freq[num]) ? count + Number(num) : count;
    }, 0);
};
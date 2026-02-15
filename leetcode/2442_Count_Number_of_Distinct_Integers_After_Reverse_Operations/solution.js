/**
 * @param {number[]} nums
 * @return {number}
 */
var countDistinctIntegers = function (nums) {
    let set = new Set(nums);
    for (let num of nums) {
        let reverse = 0;
        while (num > 0) {
            reverse = reverse * 10 + num % 10;
            num = Math.floor(num/10);
        }
        set.add(reverse);
    }
    return set.size;
};
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let res = []
    for(num of nums1) {
        if(nums2.includes(num) && !res.includes(num)) res.push(num)
    }
    return res
};
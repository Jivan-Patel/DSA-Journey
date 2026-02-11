/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number}
 */
var numberOfPairs = function (nums1, nums2, k) {
    let goodPair = 0;
    for (let i = 0; i < nums1.length; i++) {
        if (nums1[i] % k != 0) continue;
        for (let j = 0; j < nums2.length; j++) {
            if (nums1[i] % (nums2[j] * k) === 0) {
                goodPair++;
            }
        }
    }
    return goodPair;
};
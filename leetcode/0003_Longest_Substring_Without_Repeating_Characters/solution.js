/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let checkS = new Set();
    let maxLen = 0;
    let i = 0;
    let left = 0;
    while (i < s.length) {
        if (checkS.has(s[i])) {
            maxLen = (maxLen >= checkS.size) ? maxLen : checkS.size;
            while (checkS.has(s[i])) {
                checkS.delete(s[left]);
                left++;
            }
        }
        checkS.add(s[i]);
        i++;
    }
    maxLen = (maxLen >= checkS.size) ? maxLen : checkS.size;
    return maxLen;
};

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function (s, k) {
    let res = "";
    let word = 0;
    let i = 0;
    while (i < s.length && word < k) {
        res += s[i];
        i++;
        if (s[i] === " ") word++;
    }
    return res;
};
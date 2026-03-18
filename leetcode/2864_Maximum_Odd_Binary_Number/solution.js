/**
 * @param {string} s
 * @return {string}
 */
var maximumOddBinaryNumber = function (s) {
    let count1 = 0;
    let res = "";
    for (let ch of s) {
        if (ch === '1')
            count1++;
    }
    for (let i = 1; i < count1; i++)
        res += "1";
    for (let i = 0; i < s.length - count1; i++)
        res += "0";
    res += "1";
    return res;

};
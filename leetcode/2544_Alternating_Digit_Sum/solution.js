/**
 * @param {number} n
 * @return {number}
 */
var alternateDigitSum = function (n) {
    let res = n.toString().split('').reduce((count, digit, i) => count + ((i % 2 == 0) ? Number(digit) : -Number(digit)), 0)
    return res;
};
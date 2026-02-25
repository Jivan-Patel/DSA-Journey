/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function (n) {
    while (n % 4 === 0 && n > 1) {
        n /= 4;
    }
    return n === 1;
};

/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function (n) {
    if (n <= 0) return false;
    let i = 2;
    while (n != 1) {
        if (n % i === 0) {
            n = n / i;
            if (i != 2 && i != 3 && i != 5) return false;
        }
        else if (i === 2) {
            i = 3;
        }
        else if (i === 3) {
            i = 5;
        }
        else {
            return false;
        }
    }
    return true;
};
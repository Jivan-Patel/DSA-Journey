/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function (n) {
    let dprod = 1;
    let dsum = 0;
    while (n > 0) {
        let digit = n % 10;
        dprod *= digit;
        dsum += digit;
        n = Math.floor(n / 10);
    }
    return dprod - dsum;
};
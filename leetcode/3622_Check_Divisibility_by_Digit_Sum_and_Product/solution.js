/**
 * @param {number} n
 * @return {boolean}
 */
var checkDivisibility = function (n) {
    let sum = 0;
    let prod = 1;
    let temp = n;
    while(temp > 0) {
        let digit = temp % 10;
        sum+=digit;
        prod *= digit;
        temp = Math.floor(temp/10);
    }
    return n % (sum + prod) === 0;
};
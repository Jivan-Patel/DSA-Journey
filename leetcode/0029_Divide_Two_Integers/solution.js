/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    const INT_MAX = 2147483647;
    const INT_MIN = -2147483648;

    if (divisor === 0) return Infinity;
    if (dividend === 0) return 0;
    if (dividend === INT_MIN && divisor === -1) return INT_MAX;

    let result = dividend / divisor;

    return result >= 0 ? Math.floor(result) : Math.ceil(result);
};

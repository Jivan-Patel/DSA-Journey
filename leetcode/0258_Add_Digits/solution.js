/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function (num) {
    let sum = num;
    while (sum >= 10) {
        num = sum;
        sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num = Math.floor(num / 10);
        }
    }
    return sum;
};

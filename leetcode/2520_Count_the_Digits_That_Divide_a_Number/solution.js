/**
 * @param {number} num
 * @return {number}
 */
var countDigits = function (num) {
    let count = 0;
    let temp = num;
    while (temp > 0) {
        let digit = temp % 10;
        if (num % digit == 0) count++;
        temp = Math.floor(temp/10);
    }
    return count;
};
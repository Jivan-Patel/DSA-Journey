/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    let j = digits.length - 1;
    while (digits[j] === 9 && j >= 0) {
        j--;
    }
    if (j >= 0) {
        digits[j] += 1;
    }
    else {
        digits[0] = 1;
        digits.push(0);
        j = 0;
    }

    j++;
    while (j < digits.length) {
        digits[j] = 0;
        j++;
    }

    return digits;
};
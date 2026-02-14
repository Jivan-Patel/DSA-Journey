/**
 * @param {number} num
 * @return {number}
 */
var countEven = function (num) {
    const checkEvenSum = (n) => {
        let sum = 0;
        while (n > 0) {
            sum += n % 10;
            n = Math.floor(n / 10);
        }
        return sum % 2 === 0;
    }
    let count = 0;
    for (let i = 2; i <= num; i++) {
        if (checkEvenSum(i)) count++;
    }
    return count;
};
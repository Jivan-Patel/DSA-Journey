/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function (accounts) {
    let max = 0;
    for (let account of accounts) {
        let sum = account.reduce((count, num) => count + num, 0);
        if (max < sum) max = sum;
    }
    return max;
};
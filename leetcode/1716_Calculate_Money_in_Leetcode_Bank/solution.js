/**
 * @param {number} n
 * @return {number}
 */
var totalMoney = function (n) {
    let week = 0;
    let result = 0;
    while (n > 0) {
        let check = (n > 7) ? 7 : n;
        result += ((check + week) * (check + 1 + week) / 2) - (week * (week + 1) / 2);
        n = n - check;
        week++;
    }
    return result;
};
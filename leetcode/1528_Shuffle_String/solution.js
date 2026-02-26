/**
 * @param {string} s
 * @param {number[]} indices
 * @return {string}
 */
var restoreString = function (s, indices) {
    let i = 0;
    let res = [];
    for (let index of indices) {
        res[index] = s[i];
        i++;
    }
    return res.join('');
};
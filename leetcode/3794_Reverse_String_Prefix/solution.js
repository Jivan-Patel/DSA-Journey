/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reversePrefix = function (s, k) {
    s = s.split('')
    temp = s.splice(0, k).reverse();
    s.unshift(...temp);
    return s.join('');
};
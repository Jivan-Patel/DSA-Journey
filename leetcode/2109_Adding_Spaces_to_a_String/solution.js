/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function (s, spaces) {
    let result = [];
    let j = 0;
    for (let i = 0;i < s.length;i++) {
        if (i === spaces[j]) {
            result.push(" ");
            j++;
        }
        result.push(s[i]);
    }
    return result.join('');
};
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
    let i = s.length - 1;
    while (s[i] === " ") {
        i--;
    }
    let j = 0;
    while (s[i] != " " ) {
        if (i === 0) {
            j++;
            break;
        }
        i--;
        j++;
    }
    return j;
};
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function (s, t) {
    s = s.split('').sort();
    t = t.split('').sort();
    let i = 0, j = 0;
    while (t.length > j) {
        if (s[i] != t[j]) {
            return t[j]
        }
        else {
            i++;
            j++;
        }
    }

    return t[t.length - 1];
};
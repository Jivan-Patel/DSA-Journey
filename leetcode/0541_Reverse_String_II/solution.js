/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function (s, k) {
    let newStr = s.split('');
    let l = 0;
    while (l < s.length) {
        let i = l;
        let j = Math.min(k - 1 + l, s.length - 1);
        while (j > i && j >= 0) {
            let temp = newStr[i];
            newStr[i] = newStr[j];
            newStr[j] = temp;
            i++;
            j--;
        }
        l += (2 * k);
    }
    return newStr.join('');
};

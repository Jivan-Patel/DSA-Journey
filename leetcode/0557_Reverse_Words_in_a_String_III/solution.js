/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
    var reverseString = function (s) {
        s = s.split('')
        let i = 0;
        let j = s.length - 1;
        while (j > i) {
            let temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s.join('')
    };
    let newS = s.split(' ');
    for(let i = 0; i < newS.length; i++) {
        newS[i] = reverseString(newS[i])
    }

    return newS.join(' ');
};
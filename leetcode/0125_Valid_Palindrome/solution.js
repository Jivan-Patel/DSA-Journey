/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
    let newS = [];
    for (let i = 0; i < s.length; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            newS.push(s[i]);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            let samllChar = String.fromCharCode(s.charCodeAt(i) + 32);
            newS.push(samllChar);
        }
    }
    let i = 0, j = newS.length - 1;
    while (i < j) {
        if(newS[i] != newS[j]) return false;
        i++;
        j--;
    }

    return true;
};
/**
 * @param {string[]} words
 * @return {string}
 */
var firstPalindrome = function (words) {
    for (let word of words) {
        let i = 0, j = word.length - 1;
        let flag = true;
        while (i < j) {
            if (word[i] != word[j]) {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if (flag) return word;
    }
    return "";
};
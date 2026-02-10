/**
 * @param {string} word
 * @param {character} ch
 * @return {string}
 */
var reversePrefix = function(word, ch) {
    let s = word.split('');
    let i = 0;
    let j = s.indexOf(ch);
    while (i < j) {
        let temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s.join('');
};
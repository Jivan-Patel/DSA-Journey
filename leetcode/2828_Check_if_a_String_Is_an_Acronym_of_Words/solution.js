/**
 * @param {string[]} words
 * @param {string} s
 * @return {boolean}
 */
var isAcronym = function(words, s) {
    let i = 0;
    if(words.length !== s.length) return false;
    while(i < words.length) {
        if(words[i][0] !== s[i]) return false;
        i++;
    }
    return true;
};
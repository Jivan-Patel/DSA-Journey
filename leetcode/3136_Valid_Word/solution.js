/**
 * @param {string} word
 * @return {boolean}
 */
var isValid = function(word) {
    if (word.length < 3) return false
    let isVovel = false;
    let isConsonent = false;
    let vovel = new Set(['a','e','i','o','u','A','E','I','O','U']);
    for(let ch of word) {
        if((ch < 'a' || ch > 'z') && (ch < '0' || ch > '9') && (ch < 'A' || ch > 'Z')) return false;
        else if(isVovel && isConsonent) continue;
        else if(vovel.has(ch)) isVovel = true;
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) isConsonent = true;
    }
    return isVovel && isConsonent;
};
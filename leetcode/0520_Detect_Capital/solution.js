/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    if(word[0] >= 'a' && word[0] <= 'z') {
        for(let ch of word) {
            if(ch >= 'A' && ch <= 'Z') return false;
        }
        return true;
    }
    else if(!word[1]) return true
    else if (word[1] >= 'A' && word[1] <= 'Z'){
        for(let ch of word) {
            if(ch < 'A' || ch > 'Z') return false;
        }
        return true;
    }
    else {
        for(let i = 2; i < word.length; i++) {
            if(word[i] < 'a' || word[i] > 'z') return false;
        }
        return true;
    }
};
/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function (words, pref) {
    let count = 0;
    for (let word of words) {
        let check = true;
        let i = 0;
        while(i < pref.length) {
            if(word[i] != pref[i]) {
                check = false;
                break;
            }
            i++;
        }
        if(check) count++;
    }        
    return count;
};
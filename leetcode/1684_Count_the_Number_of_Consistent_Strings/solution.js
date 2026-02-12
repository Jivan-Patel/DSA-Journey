/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function (allowed, words) {
    let res = 0;
    let set = new Set(allowed);
    for (let word of words) {
        let check = true;
        for (let ch of word) {
            if (!set.has(ch)) {
                check = false;
                break;
            }
        }
        if(check) res++;
    }
    return res;
};
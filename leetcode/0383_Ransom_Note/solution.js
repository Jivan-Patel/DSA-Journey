/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function (ransomNote, magazine) {
    let rfreq = {};
    for(let i = 0; i < ransomNote.length; i++) {
        if(rfreq[ransomNote[i]]) rfreq[ransomNote[i]]++;
        else rfreq[ransomNote[i]] = 1;
    }
    for(let i = 0; i < magazine.length; i++) {
        if(rfreq[magazine[i]]) rfreq[magazine[i]]--;
    }
    for(let key in rfreq) {
        if(rfreq[key] > 0) return false;
    }
    return true;
};
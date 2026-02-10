/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */
var arrayStringsAreEqual = function (word1, word2) {
    let s1 = "";
    let s2 = "";
    for(let i = 0; i < word1.length; i++) s1 += word1[i];    
    for(let i = 0; i < word2.length; i++) s2 += word2[i];
    return s1 === s2;
};
/**
 * @param {string[]} sentences
 * @return {number}
 */
var mostWordsFound = function(sentences) {
    let maxLen = 0;
    for(let sentence of sentences)
        maxLen = Math.max(sentence.split(' ').length, maxLen);
    return maxLen;
};
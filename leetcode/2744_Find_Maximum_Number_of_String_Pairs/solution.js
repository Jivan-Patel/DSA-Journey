/**
 * @param {string[]} words
 * @return {number}
 */
var maximumNumberOfStringPairs = function (words) {
    let count = 0;
    for (let i = 0; i < words.length; i++) {
        let rev = words[i].split('').reverse().join('');
        for (let j = i + 1; j < words.length; j++) {
            if (rev == words[j]) count++;
        }
    }
    return count;
};
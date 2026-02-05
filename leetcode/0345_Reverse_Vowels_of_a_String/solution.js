/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function (s) {
    let newS = s.split('');
    let i = 0;
    let j = newS.length - 1;
    let set = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);

    while (j > i) {
        while (!set.has(newS[i]) && i < j) {
            i++;
        }
        while (!set.has(newS[j]) && i < j) {
            j--;
        }
        [newS[i], newS[j]] = [newS[j], newS[i]];
        i++;
        j--;
    }
    return newS.join('');
};
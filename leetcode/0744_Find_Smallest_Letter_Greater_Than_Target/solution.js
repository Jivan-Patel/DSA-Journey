/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function (letters, target) {
    let i = 0;
    let j = letters.length - 1;
    while (i < j) {
        let check = Math.floor((i + j) / 2);
        if (target >= letters[check]) {
            i = check + 1;
            if (letters[i] > target) return letters[i];
        }
        else if (target < letters[check]) {
            j = check - 1;
            if (letters[j] <= target) return letters[j + 1];
        }
    }
    return letters[0];
};
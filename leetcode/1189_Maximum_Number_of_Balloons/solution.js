/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function (text) {
    let balloon = { "b": 0, "a": 0, "l": 0, "o": 0, "n": 0 }
    for (let i = 0; i < text.length; i++) {
        if (balloon[text[i]] != undefined) balloon[text[i]]++;
    }
    balloon['l'] = Math.floor(balloon['l'] / 2);
    balloon['o'] = Math.floor(balloon['o'] / 2);
    let keys = Object.values(balloon);
    let min = keys[0];
    for (freq of keys) if (freq < min) min = freq;
    return min;
};
/**
 * @param {string} s
 * @return {number}
 */
var maxFreqSum = function (s) {
    let freq = {
        vowel: { 'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0 },
        consonant: {}
    };
    for (let i = 0; i < s.length; i++) {
        if (freq.vowel[s[i]] != undefined) freq.vowel[s[i]]++;
        else if (freq.consonant[s[i]] != undefined) freq.consonant[s[i]]++;
        else freq.consonant[s[i]] = 1;
    }
    let mVowel = Math.max(...Object.values(freq.vowel));
    let mConsonant = Math.max(...Object.values(freq.consonant),0);
    return mVowel + mConsonant;
};
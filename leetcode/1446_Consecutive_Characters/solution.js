/**
 * @param {string} s
 * @return {number}
 */
var maxPower = function (s) {
    let maxRep = 0;
    let curRep = 1;
    let i = 1;
    let len = s.length
    while (i < len) {
        if (s[i] === s[i - 1]) {
            curRep++;
        }
        else {
            maxRep = (maxRep < curRep) ? curRep : maxRep;
            curRep = 1;
        }
        i++;
    }
    maxRep = (maxRep < curRep) ? curRep : maxRep;

    return maxRep;
};
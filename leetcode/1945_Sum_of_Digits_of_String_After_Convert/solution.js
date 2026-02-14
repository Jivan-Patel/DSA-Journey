/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function (s, k) {
    let place = "";
    for (let ch of s) {
        let alphaPlace = ch.charCodeAt(0) - 96;
        place += alphaPlace;
    }
    while(k > 0) {
        let temp = 0;
        for(let digit of place) {
            temp += Number(digit);
        }
        place = temp.toString();
        k--;
    }

    return Number(place);
};
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function (arr) {
    let check = 0;
    for (let num of arr) {
        if (num % 2 == 1) {
            check++;
            if(check>=3) return true;
        }
        else check = 0;
    }
    return false;
};
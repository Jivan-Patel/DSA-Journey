/**
 * @param {number} n
 * @return {boolean}
 */
var isThree = function(n) {
    let count = 2;
    for(let i = 2; i <= n/2; i++) {
        if (n%i===0) {
            count++;
            if(count > 3) return false;
        }
    }
    return count === 3;
};
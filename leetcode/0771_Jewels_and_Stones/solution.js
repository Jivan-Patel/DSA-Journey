/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function(jewels, stones) {
    let set = new Set(jewels.split(''));
    let count = 0;
    for(let ch of stones) 
        if(set.has(ch)) count++;
    return count;
};